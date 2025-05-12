#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
long long p[MaxN];
long long answer[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        answer[1] += i % 2 == 1 ? p[i] : -p[i];
    }
    for (int i = 2; i <= n; i++)
    {
        answer[i] = 2 * p[i - 1] - answer[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", answer[i]);
    }
    printf("\n");
    return 0;
}
