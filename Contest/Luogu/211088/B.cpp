#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, q;
int p[MaxN];
double answer[MaxN];
std::vector<std::tuple<int, int, int>> v;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        int k, t, x;
        scanf("%d%d%d", &k, &t, &x);
        if (x == 1)
        {
            continue;
        }
        v.push_back({k, t, x});
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &p[i]);
        int cur = 0;
        double cost = 0;
        long long speed = 1;
        for (auto [k, t, x] : v)
        {
            if (speed > 1e17)
            {
                break;
            }
            if (p[i] <= k)
            {
                cost += 1.0 * (p[i] - cur) / speed;
                cur = p[i];
                break;
            }
            cost += 1.0 * (k - cur) / speed;
            cur = k;
            if (1.0 * (p[i] - cur) / speed / x * (x - 1) >= t)
            {
                speed *= x;
                cost += t;
            }
        }
        if (cur < p[i])
        {
            cost += 1.0 * (p[i] - cur) / speed;
        }
        printf("%.8lf\n", cost);
    }
    return 0;
}
