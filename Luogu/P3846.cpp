/**
 * @file Luogu\P3846.cpp
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
long long p, b, n;
std::unordered_map<long long, long long> map;
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
int main()
{
    scanf("%lld%lld%lld", &p, &b, &n);
    int m = sqrt(p) + 1;
    for (int i = 0; i < m; i++)
    {
        map[n % (p - 1) * fsp(b, i, p) % p] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        long long temp = fsp(b, i * m, p);
        if (map.count(temp))
        {
            printf("%lld\n", i * m - map[temp]);
            return 0;
        }
    }
    printf("no solution\n");
    return 0;
}