#include <cstdio>
long long n;
long long x;
int main()
{
    scanf("%lld", &x);
    n = 1;
    for (int i = 1;; i++)
    {
        n *= i;
        if (n == x)
        {
            printf("%d\n", i);
            break;
        }
        if (n > x)
        {
            printf("-1\n");
            break;
        }
    }
    return 0;
}
