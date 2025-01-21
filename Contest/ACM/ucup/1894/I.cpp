#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
bool color[MaxN];
std::vector<int> g[MaxN];
void dfs(int u, int f)
{
    color[u] = color[f] ^ true;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
    }
}
void solve()
{
    scanf("%d", &n);
    n *= 2;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> son;
    for (int i = 1; i <= n; i++)
    {
        if (int(g[i].size()) == 1)
        {
            son.push_back(i);
        }
    }
    dfs(1, 0);
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt[color[i]]++;
    }
    for (const auto &u : son)
    {
        if (cnt[0] > cnt[1] && color[u] == 0)
        {
            cnt[0]--;
            cnt[1]++;
            color[u] ^= true;
        }
        else if (cnt[1] > cnt[0] && color[u] == 1)
        {
            cnt[1]--;
            cnt[0]++;
            color[u] ^= true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", color[i]);
    }
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
/*
1
2
1 4
1 4
5 6
3 6
3 6
3 6



*/
