#include <algorithm>
#include <cstdio>
#include <functional>
constexpr int MaxN = 2e5 + 5;
int m, n, k, t;
int p[MaxN];
int l[MaxN];
int r[MaxN];
int d[MaxN];
int cf[MaxN];
bool check(int x)
{
    int minPlayer = 0x3f3f3f3f;
    for (int i = 1; i <= x; i++)
    {
        minPlayer = std::min(minPlayer, p[i]);
    }
    for (int i = 1; i <= k; i++)
    {
        if (d[i] > minPlayer)
        {
            cf[l[i]]++;
            cf[r[i] + 1]--;
        }
    }
    int cost = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        cf[i] += cf[i - 1];
        if (cf[i] >= 1)
        {
            cost += 3;
        }
        else
        {
            cost++;
        }
    }
    for (int i = 1; i <= n + 1; i++)
    {
        cf[i] = 0;
    }
    return cost <= t;
}
int main()
{
    scanf("%d%d%d%d", &m, &n, &k, &t);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + m, std::greater<>());
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
    }
    int l, r;
    l = 0;
    r = m;
    int res = 0;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            res = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d\n", res);
    return 0;
}
