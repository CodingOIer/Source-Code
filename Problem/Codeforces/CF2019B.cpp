#include <cstdio>
#include <map>
constexpr int MaxN = 2e5 + 5;
int n, q;
int p[MaxN];
std::map<long long, int> map;
void solve()
{
    map.clear();
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        map[1ll * (n - i + 1) * (i - 1) + (n - i)]++;
        if (i <= n - 1)
        {
            map[1ll * (n - i) * i] += p[i + 1] - p[i] - 1;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        long long x;
        scanf("%lld", &x);
        printf("%d ", map[x]);
    }
    printf("\n");
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
