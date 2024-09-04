## AT JOISC 2015 A コピー&ペースト 2 题解

### 思路分析

**约定：下文中将 $l$ 和 $x$ 的值均加一，这样表示把从 $l \sim r$ 的字符复制到 $x$ 的位置上。**

发现 $k$ 很小，考虑分别计算每一个需要输出的字符。

枚举初始位置 $w \in [1, k]$，记 $len = r - l + 1$，倒序处理所有的操作，有以下 $3$ 情况。

- $w < x$，不受影响。
- $x \le w < x + len$，当前位置是被复制过来的，$w \gets l + (w - x)$。
- $x + len \le w$，当前位置被复制过来的内容向右移动了 $len$ 位，$w \gets w + len$。

枚举完所有的操作后，初始字符串的第 $w$ 位就是这一位的最终字符。

### 代码实现

```cpp
#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m, k;
char s[MaxN];
std::vector<std::tuple<int, int, int>> v;
int main()
{
    scanf("%d%d", &k, &m);
    scanf("%s", s + 1);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l++;
        x++;
        v.push_back({l, r, x});
    }
    std::reverse(v.begin(), v.end());
    for (int i = 1; i <= k; i++)
    {
        int w = i;
        for (auto [l, r, x] : v)
        {
            int len = r - l + 1;
            if (w < x)
            {
                continue;
            }
            else if (w < x + len)
            {
                w = l + (w - x);
            }
            else
            {
                w -= len;
            }
        }
        printf("%c", s[w]);
    }
    printf("\n");
    return 0;
}
```

