#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
long long f[MaxN];
long long s[MaxN];
std::vector<int> link[MaxN];
bool dfs(int u, int fa)
{
    if (link[u].size() == 1)
    {
        f[u] = p[u];
        s[u] = p[u];
        return true;
    }
    long long sum, max;
    sum = 0;
    max = 0;
    for (auto v : link[u])
    {
        if (v == fa)
        {
            continue;
        }
        bool r = dfs(v, u);
        if (!r)
        {
            return false;
        }
        sum += f[v];
        s[u] += s[v];
        max = std::max(max, f[v]);
    }
    f[u] = 2ll * p[u] - sum;
    if (f[u] < 0 || sum < 0 || f[u] > s[u] || (sum - f[u]) / 2 > sum - max || (fa == 0 && f[u] > 0))
    {
        return false;
    }
    return true;
}
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        link[i].clear();
        f[i] = 0;
        s[i] = 0;
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    if (n == 2)
    {
        printf("%s\n", p[1] == p[2] ? "YES" : "NO");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (link[i].size() >= 2)
            {
                printf("%s\n", dfs(i, 0) ? "YES" : "NO");
                break;
            }
        }
    }
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