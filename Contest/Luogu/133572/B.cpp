#include <cstdio>
int t;
int n, p;
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d %d", &n, &p);
        if (p == 0)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("0");
            }
        }
        else if (2 * p + 1 > n)
        {
            printf("-1");
        }
        else
        {
            for (int j = 1; j <= n - 1 - 2 * p; j++)
            {
                printf("0");
            }
            for (int j = 1; j <= p; j++)
            {
                printf("10");
            }
            printf("1");
        }
        printf("\n");
    }
    return 0;
}