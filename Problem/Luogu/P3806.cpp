#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
class question
{
  public:
    int k;
    bool res;
    question()
    {
        k = 0;
        res = false;
    }
};
constexpr int MaxN = 1e4 + 5;
constexpr int MaxL = 1e7 + 5;
int n, m;
int top;
int root;
int t[MaxL];
int dis[MaxN];
int size[MaxN];
int max_son_size[MaxN];
bool vis[MaxN];
bool flag[MaxL];
question p[MaxN];
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
    if (dis[x] <= 1e7)
    {
        top++;
        t[top] = dis[x];
    }
    for (int i = 0; i < int(link[x].size()); i++)
    {
        int next, way;
        next = link[x][i];
        way = len[x][i];
        if (next == fa || vis[next])
        {
            continue;
        }
        dfs(next, x, l + way);
    }
}
void calc(int x)
{
    top = 1;
    t[1] = 0;
    flag[0] = true;
    int last = 1;
    for (int j = 0; j < int(link[x].size()); j++)
    {
        int next = link[x][j];
        int way = len[x][j];
        if (vis[next])
        {
            continue;
        }
        dfs(next, x, way);
        for (int i = last + 1; i <= top; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[j].k - t[i] >= 0 && flag[p[j].k - t[i]])
                {
                    p[j].res = true;
                }
            }
        }
        for (int i = last + 1; i <= top; i++)
        {
            flag[t[i]] = true;
        }
        last = top;
    }
    for (int i = 1; i <= top; i++)
    {
        flag[t[i]] = false;
    }
}
void solve(int x)
{
    calc(x);
    vis[x] = true;
    for (int next : link[x])
    {
        if (vis[next])
        {
            continue;
        }
        root = 0;
        findRoot(next, x, size[next]);
        solve(root);
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
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i].k);
    }
    max_son_size[0] = 0x3f3f3f3f;
    findRoot(1, 0, n);
    solve(root);
    for (int i = 1; i <= m; i++)
    {
        printf("%s\n", p[i].res ? "AYE" : "NAY");
    }
    return 0;
}