## [ABC241G] Round Robin 题解

### 思路分析

一道很经典的网络流建模问题。

显然的，我们可以想到向每一个比赛创建一个容量为 $1$ 的边，这个比赛再向双方选手连容量为 $1$ 的边，再从每个选手向汇点连一条容量为 $mx - 1$ 的边，其中的 $mx$ 表示当前的选手最多的胜利场数。（不是那么严谨，仅供参考）

我猜你就没听懂……下面是更「形象化」且完整的表达：

赛委会 $S$ 向每局比赛 $C_i$ 分配了 $1$ 的分值，而每局比赛可以自由地将分数分给参加它的 $2$ 个选手之一。现在赛委会 $S$ 想要 $x$ 赢，但以前的比赛无法重来，便确定 $x$ 的接下来的比赛都会赢且最多的得分为 $mx_x$。所以只有剩下的选手 $P_1, P_2, P_3, \dots , P_{x - 1}, P_{x + 1}, \dots , P_{n - 1}, P_n$ 需要比赛，不需要建立关于 $x$ 的比赛。同时对于已经有了结果的比赛，赛委会 $S$ 直接将分值给到选手 $P_i$。而为了使 $x$ 是**非并列**冠军，所以每个选手在向记分员 $T$ 汇报时必须报出 $k_i < mx - 1$ 的分数。而新闻台在报道时会检查报来的总分 $\sum_{i=1}^{n}k_i + mx$ 是否等于应有的总分 $\frac{n \times (n - 1)}{2}$，如果相同则表示有方法让 $x$ 稳拿冠军，反之不行。 

赛委会时真的黑啊……

### 代码实现

这个题的细节挺多的。

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <utility>
#include <vector>
constexpr int MaxN = 5e3 + 5;
int idx;
int n, m, s, t;
int id[MaxN];
int cnt[MaxN];
int rev[MaxN][MaxN];
int last[MaxN];
int beat[MaxN];
int was_beat[MaxN];
std::queue<int> queue;
std::vector<int> use[MaxN];
std::vector<int> max[MaxN];
std::vector<int> link[MaxN];
std::map<std::pair<int, int>, bool> map;
inline void init()
{
    idx = 0;
    for (int i = 0; i < MaxN; i++)
    {
        use[i].clear();
        max[i].clear();
        link[i].clear();
    }
}
inline void add(int u, int v, int m, int k)
{
    use[u].push_back(k);
    max[u].push_back(m);
    link[u].push_back(v);
    rev[v][u] = link[u].size() - 1;
}
inline void add(int u, int v, int m)
{
    add(u, v, m, 0);
    add(v, u, m, m);
}
inline int new_node()
{
    idx++;
    return idx;
}
void bfs()
{
    queue.push(s);
    cnt[s] = 1;
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        for (int i = 0; i < int(link[u].size()); i++)
        {
            int v = link[u][i];
            if (cnt[v] == 0 && max[u][i] - use[u][i] > 0)
            {
                cnt[v] = cnt[u] + 1;
                queue.push(v);
            }
        }
    }
}
int dfs(int u, int f)
{
    if (u == t || f == 0)
    {
        return f;
    }
    for (int i = last[u]; i < int(link[u].size()); i++)
    {
        last[u] = i;
        int v = link[u][i];
        if (cnt[u] + 1 == cnt[v])
        {
            int push = std::min(f, max[u][i] - use[u][i]);
            push = dfs(v, push);
            if (push > 0)
            {
                use[u][i] += push;
                use[v][rev[u][v]] -= push;
                return push;
            }
        }
    }
    return 0;
}
inline int Dinic()
{
    int res = 0;
    for (;;)
    {
        memset(cnt, 0, sizeof(cnt));
        bfs();
        if (cnt[t] == 0)
        {
            break;
        }
        memset(last, 0, sizeof(last));
        res += dfs(s, 1e9);
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        beat[u]++;
        was_beat[v]++;
        map[{u, v}] = true;
        map[{v, u}] = true;
    }
    for (int x = 1; x <= n; x++)
    {
        init();
        s = new_node();
        t = new_node();
        int mx = (n - 1) - was_beat[x];
        for (int i = 1; i <= n; i++)
        {
            id[i] = new_node();
            if (i == x)
            {
                continue;
            }
            for (int j = i + 1; j <= n; j++)
            {
                if (j != x && !map[{i, j}])
                {
                    int contest = new_node();
                    add(s, contest, 1);
                    add(contest, id[i], 1);
                    add(contest, id[j], 1);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == x)
            {
                continue;
            }
            add(s, id[i], beat[i]);
            add(id[i], t, mx - 1);
        }
        if (Dinic() + mx == n * (n - 1) / 2)
        {
            printf("%d ", x);
        }
    }
    return 0;
}
```

