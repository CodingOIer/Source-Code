#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
constexpr int MaxN = 2e5 + 5;
class scope
{
  public:
    int id;
    int l, r;
    scope(int a = 0)
    {
        id = a;
        l = a;
        r = a;
    }
    friend bool operator<(const scope &x, const scope &y)
    {
        return x.r > y.r;
    }
};
int n, m;
int p[MaxN];
int in[MaxN];
int answer[MaxN];
bool vis[MaxN];
scope w[MaxN];
std::vector<int> dfn;
std::vector<int> link[MaxN];
std::priority_queue<scope> queue;
void dfs(int u)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (auto v : link[u])
    {
        dfs(v);
    }
    dfn.push_back(u);
}
int main()
{
    freopen("in", "r", stdin);
    freopen("ans", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        w[i].id = i;
        if (p[i] == 0)
        {
            w[i].l = 1;
            w[i].r = n;
        }
        else
        {
            w[i].l = p[i];
            w[i].r = p[i];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        in[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            dfs(i);
        }
    }
    for (auto u : dfn)
    {
        for (auto v : link[u])
        {
            w[u].r = std::min(w[v].r, w[u].r + 1);
        }
    }
    std::reverse(dfn.begin(), dfn.end());
    for (auto u : dfn)
    {
        for (auto v : link[u])
        {
            w[v].l = std::max(w[v].l, w[u].l + 1);
        }
    }
    std::sort(w + 1, w + 1 + n, [](const scope &x, const scope &y) -> bool { return x.l < y.l; });
    auto it = w + 1;
    for (int i = 1; i <= n; i++)
    {
        for (; it != w + 1 + n && it->l <= i;)
        {
            queue.push(*it);
            it++;
        }
        if (queue.empty() || queue.top().r < i)
        {
            printf("%d\n", -1);
            return 0;
        }
        answer[queue.top().id] = i;
        queue.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}