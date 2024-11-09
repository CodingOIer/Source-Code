#include <algorithm>
#include <cstdio>
#include <tuple>
constexpr int MaxN = 2e5 + 5;
int n, m;
int x[MaxN];
int a[MaxN];
std::tuple<int, int> p[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
        p[i] = {x[i], a[i]};
    }
    sort(p + 1, p + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        x[i] = std::get<0>(p[i]);
        a[i] = std::get<1>(p[i]);
    }
    long long now = 0;
    long long answer = 0;
    for (int i = 1; i <= m; i++)
    {
        if (x[i] > now + 1)
        {
            printf("-1\n");
            return 0;
        }
        long long add = 1ll * (a[i] - 1) * a[i] / 2 + (std::max((long long)(x[i]), now + 1) - x[i]) * a[i];
        answer += add;
        now = std::max((long long)(x[i]), now + 1) + a[i] - 1;
        if (now > n)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n", answer);
    return 0;
}