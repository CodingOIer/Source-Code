#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        answer += std::max(p[i], p[i + 1]);
    }
    printf("%lld\n", answer);
    return 0;
}