#include <cstdio>
const int MaxN = 1e6 + 5;
int n, m;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[j]);
        }
        int max = 0, sum = 0, cnt = 0;
        for (int j = 1; j <= m; j++)
        {
            if (p[j] > p[max])
            {
                max = j;
                sum = cnt;
            }
            if (p[j] != 0)
            {
                cnt++;
            }
        }
        printf("%d %d\n", max, sum);
    }
    return 0;
}