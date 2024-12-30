#include <algorithm>
#include <cstdio>
#include <set>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int l[MaxN];
int r[MaxN];
int lx[MaxN];
int rx[MaxN];
std::multiset<int> set;
std::vector<std::tuple<int, int, int>> v;
void solve()
{
    v.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        l[i] = x;
        r[i] = y;
        v.push_back({x, y, i});
    }
    set.clear();
    std::sort(v.begin(), v.end(), [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) -> bool {
        return std::get<0>(x) < std::get<0>(y);
    });
    auto it = v.begin();
    for (const auto &[l, r, id] : v)
    {
        for (; it != v.end() && std::get<0>(*it) <= l;)
        {
            set.insert(std::get<1>(*it));
            it++;
        }
        set.erase(set.find(r));
        auto k = set.lower_bound(r);
        rx[id] = std::max(r, k == set.end() ? r : *k);
        set.insert(r);
    }
    set.clear();
    std::sort(v.begin(), v.end(), [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) -> bool {
        return std::get<1>(x) > std::get<1>(y);
    });
    it = v.begin();
    for (const auto &[l, r, id] : v)
    {
        for (; it != v.end() && std::get<1>(*it) >= r;)
        {
            set.insert(std::get<0>(*it));
            it++;
        }
        set.erase(set.find(l));
        auto k = set.upper_bound(l);
        lx[id] = std::min(l, k == set.begin() ? l : *(--k));
        set.insert(l);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", (l[i] - lx[i]) + (rx[i] - r[i]));
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
