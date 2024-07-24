## [ABC233F] Swap and Sort 题解

### 思路分析

显然的，对于每一个联通的块，当且仅当原序列包含的元素与目标序列包含的元素相同时有解。

并查集后哈希即可。

```cpp
for (int i = 1; i <= m; i++)
{
    int u, v;
    scanf("%d%d", &u, &v);
    link[u].push_back(v);
    link[v].push_back(u);
    map[{u, v}] = i;
    map[{v, u}] = i;
    merge(u, v);
}
for (int i = 1; i <= n; i++)
{
    v1[find(i)].push_back(i);
    v2[find(i)].push_back(p[i]);
}
for (int i = 1; i <= n; i++)
{
    unsigned long long sum1, sum2;
    sum1 = 0;
    sum2 = 0;
    for (auto x : v1[i])
    {
        sum1 += sha[x];
    }
    for (auto x : v2[i])
    {
        sum2 += sha[x];
    }
    if (sum1 != sum2)
    {
        printf("-1\n");
        return 0;
    }
}
```

现在我们可以确定这样的一组数据一定是有解的了。

现在对于每一个 $i \in [1, n]$，我们求出在原数组中 $i$ 的位置。

把题目给出的点对建成一张无向图，跑一遍 Dijkstra 即可求出最短的交换序列。（其实其他算法的答案优越性同样远远够用，但 Dijkstra 时间复杂度合适，而且较短）

然后我们把每一个交换序列里的点对两两互换即可。

为什么还不贴代码？因为 RE 了……

考虑 AtCoder 数据中的 `kill001`：

```plain
>>>>> INPUT <<<<<
9
1 6 7 8 9 2 3 4 5
14
1 2
1 9
2 3
2 4
2 5
3 4
3 5
4 5
6 7
6 8
6 9
7 8
7 9
8 9
>>>>> OUTPUT <<<<<
22
4 1 2 11 10 3 1 2 11 9 4 1 2 11 4 5 1 4 2 1 3 1
```

在我们的算法跑出 $2$ 交换序列并交换后，我们发现 $1$ 不再是在 $p_1$。

导致了后面有一个数无法找到对应的下标，进而导致 Dijkstra 在乱跑，不出意外的越界了。

如何解决？

考虑我们的算法特性，如交换下面的 $1$ 和 $5$。

```plain
>>>>> BEFORE <<<<<
5 4 3 2 1
>>>>> AFTER <<<<<
1 5 4 3 2
```

其中有可能被意外交换的是除了 $p_1, p_5$ 的 $p_2, p_3, p_4$。

因为 $p_1$ 是原位置，会被替换为 $5$。

而 $p_5$ 绝对在 $p_1$ 后面，因为前面的已经排列为了目标序列，所以不会有影响。

考虑再把 $p_2$ 移动到 $p_5$。

```plain 
>>>>> BEFORE <<<<<
1 5 4 3 2
>>>>> AFTER <<<<<
1 4 3 2 5
```

我们发现，其实这样就只交换了 $p_1$ 和 $p_5$，没有对路径上的其他点做修改。

问题迎刃而解。

### 代码实现

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <utility>
#include <vector>
std::mt19937_64 rnd(std::random_device{}());
constexpr int MaxN = 1e3 + 5;
int n, m;
int p[MaxN];
int f[MaxN];
int w[MaxN];
int pre[MaxN];
int dis[MaxN];
bool vis[MaxN];
unsigned long long sha[MaxN];
std::map<std::pair<int, int>, int> map;
std::vector<int> v1[MaxN];
std::vector<int> v2[MaxN];
std::vector<int> link[MaxN];
std::vector<int> answer;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
void merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx == fy)
    {
        return;
    }
    f[fy] = fx;
}
void Dijkstra(int u)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[u] = 0;
    memset(vis, false, sizeof(vis));
    queue.push({0, u});
    for (; !queue.empty();)
    {
        auto [_, u] = queue.top();
        queue.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (auto v : link[u])
        {
            if (dis[u] + 1 < dis[v])
            {
                pre[v] = u;
                dis[v] = dis[u] + 1;
                queue.push({dis[v], v});
            }
        }
    }
}
std::vector<std::pair<int, int>> rev(int u, int v)
{
    Dijkstra(u);
    std::vector<std::pair<int, int>> response;
    int x = v;
    for (; x != u;)
    {
        response.push_back({x, pre[x]});
        x = pre[x];
    }
    return response;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        sha[i] = rnd();
        scanf("%d", &p[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
        map[{u, v}] = i;
        map[{v, u}] = i;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        v1[find(i)].push_back(i);
        v2[find(i)].push_back(p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        unsigned long long sum1, sum2;
        sum1 = 0;
        sum2 = 0;
        for (auto x : v1[i])
        {
            sum1 += sha[x];
        }
        for (auto x : v2[i])
        {
            sum2 += sha[x];
        }
        if (sum1 != sum2)
        {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int w = i;
        for (; w <= n; w++)
        {
            if (p[w] == i)
            {
                break;
            }
        }
        auto response = rev(i, w);
        for (auto [u, v] : response)
        {
            std::swap(p[u], p[v]);
            answer.push_back(map[{u, v}]);
        }
        for (int i = int(response.size()) - 2; i >= 0; i--)
        {
            auto [u, v] = response[i];
            std::swap(p[u], p[v]);
            answer.push_back(map[{u, v}]);
        }
    }
    printf("%zu\n", answer.size());
    for (auto x : answer)
    {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
```

