## [ABC272E] Add and Mex 题解

### 思路分析

显然，我们有一个 $O(nm)$ 的暴力。

显然，也过不去。

但是对于每一个数 $x$，只有 $x \in [0, n - 1]$ 的时候才会对答案产生贡献。

- $x < 0$，显然，这和 $mex$ 无关。
- $x > n - 1$，显然，即使前面的 $n - 1$ 个数全部产生贡献，仍然缺少 $n - 1$ 这个数，再大也没有贡献了。

然后我们就有了一个看起来还是很暴力的做法：对于每一个数计算其产生贡献的区间，只在这个区间里统计他的贡献。

但是分析可得，这个做法的复杂度是正确的。

显然，对于 $i \in [1, n]$，第 $i$ 个数在**有可能**产生贡献的区间的长度是 $\lfloor \dfrac{n}{i}\rfloor$。

即：$\lfloor \dfrac{n}{1} \rfloor + \lfloor \dfrac{n}{2} \rfloor + \lfloor \dfrac{n}{3} \rfloor + \dots + \lfloor \dfrac{n}{n} \rfloor = n \ln n$。（调和级数）

显然，区间只有这么多，时间复杂度不可能高于这个。

然后再使用 `set` 维护所有询问可能有贡献的数，最后直接扫一遍算出来即可。

总的时间复杂度为：$O(n \ln n \log n) \approx O(5 \times 10 ^ 7)$，可通过此题。

### 代码实现

```cpp
#include <algorithm>
#include <cstdio>
#include <set>
constexpr int MaxN = 2e5 + 5;
int n, m;
int p[MaxN];
std::set<int> set[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        set[i].insert(0x3f3f3f3f);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        int l, r;
        if (p[i] >= 0)
        {
            l = 1;
        }
        else
        {
            l = (-p[i] + i - 1) / i;
        }
        r = std::min(m, (n - p[i] + i - 1) / i);
        for (int j = l; j <= r; j++)
        {
            set[j].insert(i * j + p[i]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int cnt = 0;
        for (auto val : set[i])
        {
            if (cnt != val)
            {
                printf("%d\n", cnt);
                break;
            }
            cnt++;
        }
    }
    return 0;
}
```

