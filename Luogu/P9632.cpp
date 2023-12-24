#include <cstdio>
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    if (k == 0)
    {
        printf("-1\n");
    }
    else
    {
        for (register int i = 1; i <= k - 1; i++)
        {
            printf("%d ", i + 1);
        }
        printf("1 ");
        for (register int i = k + 1; i <= n; i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}