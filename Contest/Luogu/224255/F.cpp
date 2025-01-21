#include <cstdio>
constexpr int MaxN = 5e1 + 5;
int n, m;
int have[MaxN];
int p[MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
            have[j] += p[i][j];
        }
    }
    int cur = 0;
    for (int i = 1; i <= m; i++)
    {
        if (have[i] >= have[cur])
        {
            cur = i;
        }
    }
    int cnt = 0;
    int best = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i][cur] > best)
        {
            best = p[i][cur];
            cnt = 1;
        }
        else if (p[i][cur] == best)
        {
            cnt++;
        }
    }
    printf("%d %d\n", best, cnt);
    return 0;
}
