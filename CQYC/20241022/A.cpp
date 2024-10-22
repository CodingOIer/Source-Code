// ! 100

#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 2e3 + 5;
int n, k;
int in[MaxN][MaxN];
bool vis[MaxN][MaxN];
std::vector<int> g[MaxN][MaxN];
std::map<int, int> map[MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (vis[u][v])
            {
                printf("ERR1\n");
                return 0;
            }
            vis[u][v] = true;
            vis[v][u] = true;
            in[i][u]++;
            in[i][v]++;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][in[i][j]]++;
        }
    }
    if (n % 2 == 0)
    {
        for (int i = 1; i <= k; i++)
        {
            if (map[i][n / 2] == 2 && map[i][1] == n - 2)
            {
                // Do no thing.
            }
            else
            {
                printf("ERR2\n");
                return 0;
            }
        }
    }
    else if (n % 2 == 1)
    {
        for (int i = 1; i <= k; i++)
        {
            if (map[i][n / 2] == 1 && map[i][n / 2 + 1] == 1 && map[i][1] == n - 2)
            {
                // Do no thing.
            }
            else
            {
                printf("ERR2\n");
                return 0;
            }
        }
    }
    printf("OK\n");
    return 0;
}