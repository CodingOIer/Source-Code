#include <algorithm>
#include <cstdio>
#include <cstdlib>
constexpr int MaxN = 1e5 + 5;
int n, x;
int p[MaxN];
void solve()
{
    scanf("%d%d", &n, &x);
    for (int i = 0; i <= n + 1; i++)
    {
        p[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    if (n <= 3)
    {
        printf("%d\n", std::max({p[1], p[2], p[3]}));
        return;
    }
    int less = 0;
    for (int i = 1; i <= n; i++)
    {
        if (abs(x - i) > 1 && p[i] <= p[x - 1] + p[x] + p[x + 1] - std::min({p[x - 1], p[x], p[x + 1]}) -
                                          std::max({p[x - 1], p[x], p[x + 1]}))
        {
            less++;
        }
    }
    if (less == 0)
    {
        printf("%d\n", std::max({p[x - 1], p[x], p[x + 1]}));
    }
    else
    {
        printf("%d\n", p[x - 1] + p[x] + p[x + 1] - std::min({p[x - 1], p[x], p[x + 1]}) -
                           std::max({p[x - 1], p[x], p[x + 1]}));
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
