#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e5 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    int cur = 0;
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (; p[cur + 1] <= p[i] / 2;)
        {
            cur++;
        }
        answer += cur;
    }
    printf("%lld\n", answer);
    return 0;
}
