#include <cstdio>
constexpr int MaxN = 3e5 + 5;
int n;
long long answer;
long long p[MaxN];
int main()
{
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        sum += p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum -= p[i];
        answer += p[i] * sum;
    }
    printf("%lld\n", answer);
    return 0;
}