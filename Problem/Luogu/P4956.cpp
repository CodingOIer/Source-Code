#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    n /= 364;
    if (n <= 103)
    {
        printf("%d\n", n - 3);
        printf("%d\n", 1);
    }
    else
    {
        if (n % 3 == 0)
        {
            printf("%d\n", 99);
            printf("%d\n", (n - 99) / 3);
        }
        if (n % 3 == 1)
        {
            printf("%d\n", 100);
            printf("%d\n", (n - 100) / 3);
        }
        if (n % 3 == 2)
        {
            printf("%d\n", 98);
            printf("%d\n", (n - 98) / 3);
        }
    }
    return 0;
}