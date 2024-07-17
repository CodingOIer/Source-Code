#include <cstdio>
#include <map>
constexpr int MaxN = 2e5 + 5;
int n;
long long p[MaxN];
std::map<long long, bool> cnt;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        cnt[p[i]] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= 2e9; j *= 2)
        {
            if (cnt.count(p[i] + j) && cnt.count(p[i] + 2 * j))
            {
                printf("3\n");
                printf("%lld %lld %lld\n", p[i], p[i] + j, p[i] + 2 * j);
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= 2e9; j *= 2)
        {
            if (cnt.count(p[i] + j))
            {
                printf("2\n");
                printf("%lld %lld\n", p[i], p[i] + j);
                return 0;
            }
        }
    }
    printf("1\n");
    printf("%lld\n", p[1]);
    return 0;
}