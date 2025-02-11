#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e6 + 5;
long long a, b, c, d;
long long suffix[MaxN];
int main()
{
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    long long answer = 0;
    for (long long x = std::max(a, b + c); x >= c; x--)
    {
        suffix[x] = suffix[x + 1];
        if (c <= x && x <= d)
        {
            answer += suffix[x];
        }
        long long minZ = std::max(a, x - c);
        long long maxZ = std::min(b, x - b);
        suffix[x] += std::max(0ll, maxZ - minZ + 1);
    }
    printf("%lld\n", answer);
    return 0;
}
