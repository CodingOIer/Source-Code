#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e1 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    long long s = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        s += p[i];
    }
    long long answer = 0x7f7f7f7f7f7f7f7f;
    for (int j = 0; j < (1 << n); j++)
    {
        long long k = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((j >> (i - 1)) & 1)
            {
                k += p[i];
            }
        }
        answer = std::min(answer, std::max(k, s - k));
    }
    printf("%lld\n", answer);
    return 0;
}