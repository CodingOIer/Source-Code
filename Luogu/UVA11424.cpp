#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
long long p[MaxN];
int main()
{
    for (;;)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        long long answer = 0;
        for (long long i = n; i >= 1; i--)
        {
            p[i] = (n / i) * (n / i);
            for (long long j = i * 2; j <= n; j += i)
            {
                p[i] -= p[j];
            }
            answer += p[i] * i;
            answer -= i;
        }
        printf("%lld\n", answer / 2);
    }
    return 0;
}