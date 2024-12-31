#include <cstdio>
#include <cstdlib>
#include <utility>
constexpr int MaxN = 2e1 + 5;
int n, m;
int end;
int a[MaxN];
int b[MaxN];
int pre[MaxN];
bool vis[MaxN];
bool dfs(int u)
{
    if (u > n)
    {
        return pre[n] == end;
    }
    for (int i = 1; i <= m; i++)
    {
        if (vis[i])
        {
            continue;
        }
        if (b[i] == pre[u - 1])
        {
            std::swap(a[i], b[i]);
        }
        if (a[i] == pre[u - 1])
        {
            pre[u] = b[i];
            vis[i] = true;
            if (dfs(u + 1))
            {
                return true;
            }
            vis[i] = false;
        }
    }
    return false;
}
void solve()
{
    scanf("%d", &n);
    if (n == 0)
    {
        exit(0);
    }
    scanf("%d", &m);
    scanf("%*d%d", &pre[0]);
    scanf("%d%*d", &end);
    for (int i = 1; i <= m; i++)
    {
        vis[i] = false;
        scanf("%d%d", &a[i], &b[i]);
    }
    printf("%s\n", dfs(1) ? "YES" : "NO");
}
int main()
{
    for (;;)
    {
        solve();
    }
    return 0;
}
