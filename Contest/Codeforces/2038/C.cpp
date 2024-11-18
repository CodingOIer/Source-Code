#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
std::vector<int> v;
std::map<int, int> map;
inline void solve()
{
    v.clear();
    map.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        map[p[i]]++;
    }
    for (const auto &val : map)
    {
        int cnt = val.second;
        for (; cnt >= 2;)
        {
            cnt -= 2;
            v.push_back(val.first);
        }
    }
    std::sort(v.begin(), v.end());
    if (v.size() < 4)
    {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    int sx, sy, ex, ey;
    sx = v[0];
    sy = v[1];
    ex = v[v.size() - 1];
    ey = v[v.size() - 2];
    if (1ll * (ex - sx) * (ey - sy) > 1ll * (ex - sy) * (ey - sx))
    {
        printf("%d %d %d %d %d %d %d %d\n", sx, sy, sx, ey, ex, sy, ex, ey);
    }
    else
    {
        std::swap(sx, sy);
        printf("%d %d %d %d %d %d %d %d\n", sx, sy, sx, ey, ex, sy, ex, ey);
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
