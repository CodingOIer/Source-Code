#include <cstdio>
int n;
char out;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        out = '-';
        for (int j = 1; j <= 9; j++)
        {
            if (n % j == 0 && i % (n / j) == 0)
            {
                out = '0' + j;
                break;
            }
        }
        printf("%c", out);
    }
    printf("\n");
    return 0;
}