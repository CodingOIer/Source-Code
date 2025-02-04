## [AGC014D] Black and White Tree 题解

### 思路分析

后手需要让每一个百点旁边起码有一个黑点。

考虑特殊的叶子情况。

显然叶子只有一个与之相连的节点，令叶子记为 $x$，与叶子节点相连的唯一节点记为 $y$。

当然如果上一步不满足（只剩下一个点了），显然就是先手必胜了。

不难发现先手最优的情况为选择 $y$。

如果先选择 $x$，则后手会选 $y$，这时所有与 $y$ 相邻的节点涂白都没有意义了。

也就是说至少丢失 $1$ 个节点。

而如果选择 $y$，则后手必须选择 $x$。

如果不选择 $x$ 则下一步先手选择 $x$ 那么 $x$ 周围将没有黑点。

显然此方案不会对除了这两个点以外的节点产生影响，所以仅仅会丢失 $1$ 个节点。

显然选择 $y$ 优于选择 $x$。

那么我们以任意顺序模拟，如果剩下了节点则先手一定能染出一个孤立的白色。

否则染不出来，后手胜利。

### 代码实现

一次简单的 dfs 即可。

```cpp
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n;
bool kill[MaxN];
std::vector<int> g[MaxN];
void dfs(int u, int f)
{
    int w = 0;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
        if (!kill[v])
        {
            w = v;
        }
    }
    if (w != 0)
    {
        kill[u] = true;
        kill[w] = true;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!kill[i])
        {
            printf("First\n");
            return 0;
        }
    }
    printf("Second\n");
    return 0;
}
```



