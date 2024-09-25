#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
long long p[MaxN];
int main()
{
    scanf("%d", &n);
    long long answer = 0;
    for (long long i = n; i >= 1; i--)
    {
        p[i] = (n / i) * (n / i);
        for (long long j = i * 2; j <= n; j += i)
        {
            p[i] -= p[j];
        }
        if (i == 1)
        {
            answer += p[i] * i;
        }
    }
    printf("%lld\n", n == 1 ? 0 : answer - 2);
    return 0;
}