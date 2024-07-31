#include <cstdio>
int n, m;
long long p;
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res *= x;
            res %= p;
        }
        y >>= 1;
        x *= x;
        x %= p;
    }
    return res;
}
long long inv(long long x)
{
    return fsp(x, p - 2);
}
long long A(long long n, long long m)
{
    long long res = 1;
    for (long long i = n; i >= n - m + 1; i--)
    {
        res *= i;
        res %= p;
    }
    return res;
}
long long C(long long n, long long m)
{
    return A(n, m) * inv(A(m, m)) % p;
}
int main()
{
    scanf("%d%d%lld", &n, &m, &p);
    printf("%lld\n", C(n + m - 1, 2 * m - 1));
    return 0;
}