#include <algorithm>
#include <cmath>
#include <cstdio>
const int mod = 1e9 + 7;
const int MaxN = 1e4 + 5;
long long n;
long long answer;
long long lcm;
long long p[MaxN];
int main()
{
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    lcm = p[1];
    for (long long i = 2; i <= n; i++)
    {
        lcm = (lcm * p[i]) / std::__gcd(lcm, p[i]);
    }
    for (long long i = 1; i <= n; i++)
    {
        answer = (answer + lcm / p[i]) % mod;
    }
    printf("%lld\n", answer);
    return 0;
}