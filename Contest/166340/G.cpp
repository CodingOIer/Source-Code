#include <cstdio>
constexpr int MaxN = 5e3 + 5;
int n, m;
int need[MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            scanf("%d", &x);
            need[i][x]++;
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int l;
        scanf("%d", &l);
        for (int j = 1; j <= l; j++)
        {
            int x;
            scanf("%d", &x);
            need[i][x]--;
        }
        int point = 2;
        for (int j = 1; j <= 5e3; j++)
        {
            if (need[i][j] > 0)
            {
                point = 0;
            }
        }
        answer += point;
    }
    printf("%d\n", answer);
    return 0;
}