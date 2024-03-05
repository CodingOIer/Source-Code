#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e4 + 5;
int n, m;
int root;
int dis[MaxN];
int size[MaxN];
int max_son_size[MaxN];
bool vis[MaxN];
std::vector<int> len[MaxN];
std::vector<int> link[MaxN];
void findRoot(int x, int fa, int sum)
{
    size[x] = 1;
    max_son_size[x] = 0;
    for (int next : link[x])
    {
        if (next == fa || vis[next])
        {
            continue;
        }
        findRoot(next, x, sum);
        size[x] += size[next];
        max_son_size[x] = std::max(max_son_size[x], size[next]);
    }
    max_son_size[x] = std::max(max_son_size[x], sum - size[x]);
    if (max_son_size[x] < max_son_size[root])
    {
        root = x;
    }
}
void dfs(int x, int fa, int l)
{
    dis[x] = l;
    for (int i = 0; i < int(link[x].size()); i++)
    {
        int next, way;
        next = link[x][i];
        way = len[x][i];
        if (next == fa)
        {
            continue;
        }
        dfs(next, x, l + way);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        len[u].push_back(w);
        len[v].push_back(w);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    return 0;
}