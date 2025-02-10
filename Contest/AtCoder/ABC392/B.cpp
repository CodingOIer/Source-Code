#include <cstdio>
constexpr int MaxN = 1e3 + 3;
int n, m;
int p[MaxN];
bool vis[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
        vis[p[i]] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
