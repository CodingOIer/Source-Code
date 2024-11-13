#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%02d", n * (i - 1) + j);
        }
        printf("\n");
    }
    printf("\n");
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (n - j + 1 <= i)
            {
                printf("%02d", cnt);
                cnt++;
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}