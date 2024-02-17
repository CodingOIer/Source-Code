#include <algorithm>
#include <cstdio>
long long answer;
long long n, m, k;
bool next(long long x, long long a)
{
    if ((x + a) % n == 0 && (x + a) % m == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("tests.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    long long x, y;
    x = 0;
    y = 0;
    for (long long i = 1; i <= k; i++)
    {
        if (x + n < y + m)
        {
            if (next(x, n))
            {
                i--;
            }
            else
            {
                printf("%lld\n", x + n);
            }
            x += n;
        }
        else
        {
            if (next(y, m))
            {
                i--;
            }
            else
            {
                printf("%lld\n", y + m);
            }
            y += m;
        }
    }
    printf("%lld\n", x > y ? x : y);
    return 0;
}