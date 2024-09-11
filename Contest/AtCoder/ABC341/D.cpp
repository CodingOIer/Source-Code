#include <algorithm>
#include <cstdio>
long long answer;
long long n, m, k;
long long gcd(long long x, long long y)
{
    for (;;)
    {
        if (x == y || x == 0)
        {
            return y;
        }
        else if (y == 0)
        {
            return x;
        }
        else if (x > y)
        {
            x %= y;
        }
        else if (x < y)
        {
            y %= x;
        }
    }
}
inline bool check(long long x)
{
    if (x % n == 0 && x % m == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    long long l = n * m / gcd(n, m);
    if (n > m)
    {
        std::swap(n, m);
    }
    long long back = n + m - n * m / l * 2;
    long long need = k / back;
    k %= back;
    answer = need * n * m;
    if (k == 0)
    {
        printf("%lld\n", answer - n);
        return 0;
    }
    long long x, y;
    x = answer;
    y = answer;
    for (long long i = 1; i <= k; i++)
    {
        if (x + n < y + m)
        {
            x += n;
            if (!check(x))
            {
                i--;
            }
        }
        else
        {
            y += m;
            if (!check(y))
            {
                i--;
            }
        }
    }
    printf("%lld\n", x > y ? x : y);
    return 0;
}