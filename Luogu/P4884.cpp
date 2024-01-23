/**
 * @file Luogu\P4884.cpp
 * @author CodingOIer (redefinition0726@163.com)
 * @brief Luogu
 * @version 1.0
 * @date 2024-01-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cmath>
#include <cstdio>
#include <unordered_map>
long long k, m;
long long fsp(long long x, long long y, long long p)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y % 2 == 1)
        {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        y /= 2;
    }
    return res;
}
long long bsgs(long long x, long long y, long long p)
{
    std::unordered_map<long long, long long> map;
    long long m = sqrt(p) + 1;
    for (int i = 0; i < m; i++)
    {
        map[y % (p - 1) * fsp(x, i, p) % p] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        long long temp = fsp(x, i * m, p);
        if (map.count(temp))
        {
            return i * m - map[temp];
        }
    }
    return -1;
}
signed main()
{
    scanf("%lld%lld", &k, &m);
    printf("%lld\n", bsgs(10, (9 * k + 1) % m, m));
    return 0;
}