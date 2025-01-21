#include <algorithm>
#include <cstdio>
#include <set>
#include <tuple>
#include <vector>
constexpr int MaxN = 3e5 + 5;
int n;
int a[MaxN];
int b[MaxN];
bool vis[MaxN];
std::set<std::tuple<int, int, int>> setA;
std::set<std::tuple<int, int, int>> setB;
void solve()
{
    setA.clear();
    setB.clear();
    scanf("%d", &n);
    for (int i = 1; i <= 3 * n; i++)
    {
        vis[i] = false;
        scanf("%d%d", &a[i], &b[i]);
        setA.insert({a[i], -b[i], i});
        setB.insert({b[i], -a[i], i});
    }
    std::vector<std::tuple<int, int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        auto [_a, _b, x] = *setB.rbegin();
        setA.erase({a[x], -b[x], x});
        setB.erase({b[x], -a[x], x});
        auto it = setA.end();
        it--;
        if (std::get<1>(*it) == x)
        {
            it--;
        }
        auto [_c, _d, y] = *it;
        setA.erase({a[y], -b[y], y});
        setB.erase({b[y], -a[y], y});
        if (b[y] < a[x])
        {
            printf("No\n");
            return;
        }
        it = setB.lower_bound({std::max(a[y], a[x]), -0x7f7f7f7f, 0});
        if (it == setB.end())
        {
            printf("No\n");
            return;
        }
        auto [_e, _f, z] = *it;
        setA.erase({a[z], -b[z], z});
        setB.erase({b[z], -a[z], z});
        v.push_back({x, y, z});
    }
    printf("Yes\n");
    for (const auto &[a, b, c] : v)
    {
        printf("%d %d %d\n", a, b, c);
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
