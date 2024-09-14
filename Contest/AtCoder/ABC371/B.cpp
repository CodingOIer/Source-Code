#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, m;
bool vis[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x;
        char y;
        scanf("%d %c", &x, &y);
        if (y == 'M')
        {
            if (vis[x])
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }
            vis[x] = true;
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}