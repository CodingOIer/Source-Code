#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e5 + 5;
int n;
char s[MaxN];
long long cnt[128];
long long sum[128];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[s[i]] != 0)
        {
            answer += i * cnt[s[i]] - sum[s[i]] - cnt[s[i]];
        }
        cnt[s[i]]++;
        sum[s[i]] += i;
    }
    printf("%lld\n", answer);
    return 0;
}