#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define debug printf("Debug\n")
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int MaxN = 1e5 + 5;
long long n, m;
long long p[MaxN];
long long first_lcm;
long long second_lcm;
long long first[MaxN];
long long lcm(long long x, long long y)
{
    return (x * y) / std::__gcd(x, y);
}
int main()
{
    freopen("in.in", "r", stdin);
    scanf("%lld%lld", &n, &m);
    first_lcm = 1;
    second_lcm = 1;
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        first[i] = p[i] / 2;
        first_lcm = lcm(first_lcm, first[i]);
        second_lcm = lcm(second_lcm, p[i]);
    }
    printf("%lld %lld\n", first_lcm, second_lcm);
    if (first_lcm > m)
    {
        printf("0\n");
        return 0;
    }
    for (long long i = 1; i <= n; i++)
    {
        if (first[i] % first_lcm == 0)
        {
            printf("0\n");
            return 0;
        }
    }
    printf("%lld\n", 1 + (m - first_lcm) / second_lcm);
    return 0;
}