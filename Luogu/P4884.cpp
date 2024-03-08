#include <cmath>
#include <cstdio>
#include <unordered_map>
long long k, m;
inline long long times(long long x, long long y, long long p)
{
    long long z = (long double)x / p * y;
    long long res = (unsigned long long)x * y - (unsigned long long)z * p;
    return (res + p) % p;
}
long long fsp(long long x, long long y, long long p)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y % 2 == 1)
        {
            res = times(res, x, p);
        }
        x = times(x, x, p);
        y /= 2;
    }
    return res;
}
long long bsgs(long long x, long long y, long long p)
{
    std::unordered_map<long long, long long> map;
    long long m = sqrt(p) + 1;
    for (long long i = 0; i < m; i++)
    {
        map[times(y % (p - 1), fsp(x, i, p), p)] = i;
    }
    for (long long i = 1; i <= m; i++)
    {
        long long temp = fsp(x, i * m, p);
        if (map.count(temp))
        {
            return i * m - map[temp];
        }
    }
    return -1;
}
int main()
{
    scanf("%lld%lld", &k, &m);
    printf("%lld\n", bsgs(10, (9ll * k + 1) % m, m));
    return 0;
}