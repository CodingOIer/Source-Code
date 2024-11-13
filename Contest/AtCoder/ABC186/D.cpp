#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
long long p[MaxN];
long long sl, sr;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        sr += p[i];
    }
    std::sort(p + 1, p + 1 + n);
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        sr -= p[i];
        answer += (p[i] * (i - 1) - sl) + (sr - p[i] * (n - i));
        sl += p[i];
    }
    printf("%lld\n", answer / 2);
    return 0;
}