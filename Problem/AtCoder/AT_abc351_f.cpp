#include <algorithm>
#include <cstdio>
#include <functional>
constexpr int MaxN = 4e5 + 5;
int n;
long long p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + 1 + n, std::greater<>());
    long long answer = 0;
    long long prefixSum = 0;
    for (int i = 1; i <= n; i++)
    {
        prefixSum += p[i];
        answer += prefixSum - p[i] * i;
    }
    printf("%lld\n", answer);
    return 0;
}
