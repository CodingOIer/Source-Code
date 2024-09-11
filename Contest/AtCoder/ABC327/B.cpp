#include <cmath>
#include <cstdio>
long long n;
int main()
{
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
    {
        long long res = 1;
        for (long long j = 1; j <= i; j++)
        {
            res *= i;
            if (res > n)
            {
                printf("-1\n");
                return 0;
            }
        }
        if (res == n)
        {
            printf("%lld\n", i);
            return 0;
        }
    }
    return 0;
}