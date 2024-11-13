## [ABC186F] Rook on Grid 题解

### 思路分析

显然，如果走了两步，则第一步的方向肯定是垂直于第二步的方向的，不然可以直接一步走到。

那么就成了对于每一个 $x = 1$ 或 $y = 1$ 作为起点，垂直于 $x$ 或 $y$ 轴走任意步。

如图所示：

![](https://cdn.luogu.com.cn/upload/image_hosting/kfviv489.png)

图中绿色标注的是 $y = 1$ 能够走到的格子，而青色标注的是 $x = 1$ 能走到的格子。

显然有重复的，需要去重。

我们钦定 $y = 1$ 能够走到的格子数的贡献是**不需要撤销**的，然后撤销 $x = 1$ 的贡献。

令 $col_i$ 表示 $x = 1, y = i$ 时能够走的最远距离。

显然，对于 $i \in [1, w]$ 其中需要撤销的贡献就是 $x \in [1, col_i]$ 中所有能够走的距离 $\ge i$ 的。

显然，不考虑 $x \in [1, col_i]$ 则答案递减。

即 $t_i$ 表示 $x = i$ 目前是否仍然可以到达。

则每次需要撤销的贡献为 $\sum_{i = 1}^{col_i} [t_i]$。

则我们需要维护单点修改，区间查询，树状数组即可。

（<https://atcoder.jp/contests/abc186/submissions/59734313>）

考虑如下 Hack：

![](https://cdn.luogu.com.cn/upload/image_hosting/azg8h7vx.png)

显然，对于 $x \in [2, 3]$，无法产生横着走的贡献。

所以，对于 $x = 1$ 或 $y = 1$ 的情况，我们要记录下 $y$ 或 $x$ 的最小值，记为 $ly$ 和 $lx$。

显然，对于 $x \in [lx, h]$ 行，$y \in [ly, w]$ 列的贡献为 $0$，记得判掉。

### 代码实现

```cpp
#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int h, w, m;
int ln[MaxN];
int col[MaxN];
long long tree[MaxN];
long long answer;
std::vector<int> v[MaxN];
inline void change(int x, int val)
{
    for (; x <= h; x += x & -x)
    {
        tree[x] += val;
    }
}
inline long long query(int x)
{
    long long res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
int main()
{
    scanf("%d%d%d", &h, &w, &m);
    int lh, lw;
    lh = h;
    lw = w;
    for (int i = 1; i <= h; i++)
    {
        ln[i] = w;
    }
    for (int i = 1; i <= w; i++)
    {
        col[i] = h;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ln[x] = std::min(ln[x], y - 1);
        col[y] = std::min(col[y], x - 1);
        if (x == 1)
        {
            lw = std::min(lw, y - 1);
        }
        if (y == 1)
        {
            lh = std::min(lh, x - 1);
        }
    }
    for (int i = lh + 1; i <= h; i++)
    {
        ln[i] = 0;
    }
    for (int i = lw + 1; i <= w; i++)
    {
        col[i] = 0;
    }
    for (int i = 1; i <= w; i++)
    {
        answer += col[i];
    }
    for (int i = 1; i <= h; i++)
    {
        answer += ln[i];
        v[ln[i]].push_back(i);
    }
    for (int i = 1; i <= h; i++)
    {
        change(i, 1);
    }
    for (auto val : v[0])
    {
        change(val, -1);
    }
    for (int i = 1; i <= w; i++)
    {
        answer -= query(col[i]);
        for (auto val : v[i])
        {
            change(val, -1);
        }
    }
    printf("%lld\n", answer);
    return 0;
}
```



