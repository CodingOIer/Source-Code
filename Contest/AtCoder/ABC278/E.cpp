#include <cstdio>
#include <cstring>
constexpr int MaxN = 3e2 + 5;
int n, m, c, h, w;
int diff;
int cnt[MaxN];
int p[MaxN][MaxN];
int answer[MaxN][MaxN];
inline void ad(int x)
{
    cnt[x]++;
    if (cnt[x] == 1)
    {
        diff++;
    }
}
inline void rm(int x)
{
    cnt[x]--;
    if (cnt[x] == 0)
    {
        diff--;
    }
}
int main()
{
    scanf("%d%d%d%d%d", &n, &m, &c, &h, &w);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 1; i <= n - h + 1; i++)
    {
        diff = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ad(p[i][j]);
            }
        }
        for (int j = 0; j < h; j++)
        {
            for (int k = 1; k <= w; k++)
            {
                rm(p[i + j][k]);
            }
        }
        answer[i][1] = diff;
        for (int j = 1; j <= m - w; j++)
        {
            for (int k = 0; k < h; k++)
            {
                ad(p[i + k][j]);
                rm(p[i + k][j + w]);
            }
            answer[i][j + 1] = diff;
        }
    }
    for (int i = 1; i <= n - h + 1; i++)
    {
        for (int j = 1; j <= m - w + 1; j++)
        {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    return 0;
}