#include <algorithm>
#include <cstdio>
#include <numeric>
constexpr int MaxN = 1e1 + 5;
int n;
int answer = 0x7f7f7f7f;
int m1, m2;
int f[MaxN];
int p[MaxN][MaxN];
bool vis[MaxN][MaxN];
bool have[MaxN][MaxN];
inline void update()
{
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (vis[i][j] ^ have[f[i]][f[j]])
            {
                temp += p[i][j];
            }
        }
    }
    answer = std::min(answer, temp);
}
int main()
{
    scanf("%d", &n);
    scanf("%d", &m1);
    for (int i = 1; i <= m1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        have[y][x] = true;
        have[x][y] = true;
    }
    scanf("%d", &m2);
    for (int i = 1; i <= m2; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vis[y][x] = true;
        vis[x][y] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            scanf("%d", &p[i][j]);
            p[j][i] = p[i][j];
        }
    }
    std::iota(f + 1, f + 1 + n, 1);
    for (;;)
    {
        update();
        if (!std::next_permutation(f + 1, f + 1 + n))
        {
            break;
        }
    }
    printf("%d\n", answer);
    return 0;
}