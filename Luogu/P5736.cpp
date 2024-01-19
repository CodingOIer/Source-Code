#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
int p[MaxN];
bool vis[MaxN];
void init()
{
    vis[1] = true;
    for (int i = 2; i <= 1e5; i++)
    {
        if (vis[i])
        {
            continue;
        }
        for (int j = 2; i * j <= 1e5; j++)
        {
            vis[i * j] = true;
        }
    }
    return;
}
int main()
{
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[p[i]])
        {
            printf("%d ", p[i]);
        }
    }
    printf("\n");
    return 0;
}