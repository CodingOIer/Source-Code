#include <cstdio>
#include <map>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e5 + 5;
constexpr long long Mod = 1e9 + 7;
int n, m;
int p[MaxN];
bool vis[MaxN];
long long pow10[MaxN];
std::vector<int> answer;
std::map<std::tuple<int, int>, bool> near;
void dfs(int u)
{
    if (u > n)
    {
        long long hash = 0;
        for (int i = 1; i <= n; i++)
        {
            hash += pow10[n - i] * p[i];
            hash %= Mod;
        }
        answer.push_back(hash);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        p[u] = i;
        bool suc = true;
        for (int j = 1; u != 1 && suc && j <= u - 1; j++)
        {
            if ((j + 1 == u) ^ (near[{p[j], p[u]}]))
            {
                suc = false;
            }
        }
        if (suc)
        {
            vis[i] = true;
            dfs(u + 1);
            vis[i] = false;
        }
    }
}
void solve()
{
    near.clear();
    answer.clear();
    scanf("%d%d", &n, &m);
    pow10[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pow10[i] = pow10[i - 1] * 10 % Mod;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        near[{u, v}] = true;
    }
    dfs(1);
    printf("%zu\n", answer.size());
    for (const auto &val : answer)
    {
        printf("%d ", val);
    }
    if (!answer.empty())
    {
        printf("\n");
    }
}
int main()
{
    int testid, t;
    scanf("%d%d", &testid, &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
