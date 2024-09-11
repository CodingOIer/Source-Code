#include <cmath>
#include <cstdio>
long long n;
int main()
{
    scanf("%lld", &n);
    for (long long x = 0; powl(2, x) <= n; x++)
    {
        for (long long y = 0; powl(2, x) * powl(3, y) <= n; y++)
        {
            if (powl(2, x) * powl(3, y) == n)
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}