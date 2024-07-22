#include <cstdio>
#include <map>
constexpr int MaxN = 2e5 + 5;
int n;
long long k;
long long p[MaxN];
long long sum[MaxN];
std::map<long long, int> map;
int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        sum[i] = sum[i - 1] + p[i];
    }
    map[0]++;
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer += map[sum[i] - k];
        map[sum[i]]++;
    }
    printf("%lld\n", answer);
    return 0;
}