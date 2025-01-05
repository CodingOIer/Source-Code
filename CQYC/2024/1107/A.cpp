// ~ 100

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, q;
int block;
int p[MaxN];
int fa[MaxN];
int id[MaxN];
int gid[MaxN];
int ref[MaxN];
int have[MaxN];
int depth[MaxN];
int answer[MaxN];
std::vector<int> s;
std::vector<int> g[MaxN];
std::map<int, int> how[MaxN];
std::vector<std::tuple<int, int, int>> ask;
std::vector<std::tuple<int, int, int>> wait[MaxN];
int init(int u, int f)
{
    fa[u] = f;
    depth[u] = depth[f] + 1;
    int gp = -1;
    bool son = true;
    for (auto v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        son = false;
        gp = init(v, u);
        how[u][gp] = v;
    }
    if (son)
    {
        gid[u] = u;
        s.push_back(u);
        return u;
    }
    else
    {
        assert(gp != -1);
        gid[u] = gp;
        return gp;
    }
}
inline void solve(int u, std::vector<std::tuple<int, int, int>> &v)
{
    int cu = u;
    for (int i = depth[u]; i >= 1; i--)
    {
        ref[i] = cu;
        cu = fa[cu];
    }
    for (auto &k : v)
    {
        std::get<0>(k) = depth[std::get<0>(k)];
        std::get<1>(k) = depth[std::get<1>(k)];
    }
    block = std::sqrt(depth[u]);
    std::sort(v.begin(), v.end(), [](const std::tuple<int, int, int> x, const std::tuple<int, int, int> y) -> bool {
        return std::get<0>(x) / block == std::get<0>(y) / block
                   ? (std::get<1>(x) == std::get<1>(y) ? false : (std::get<0>(x) / block) % 2 == 1) ^
                         (std::get<1>(x) < std::get<1>(y))
                   : std::get<0>(x) < std::get<0>(y);
    });
    int cnt = 0;
    int l, r;
    l = 1;
    r = 1;
    cnt = 1;
    have[p[1]] = 1;
    for (auto k : v)
    {
        int wantL, wantR, id;
        std::tie(wantL, wantR, id) = k;
        for (; wantL < l;)
        {
            l--;
            have[p[ref[l]]]++;
            cnt += have[p[ref[l]]] == 1 ? 1 : 0;
        }
        for (; r < wantR;)
        {
            r++;
            have[p[ref[r]]]++;
            cnt += have[p[ref[r]]] == 1 ? 1 : 0;
        }
        for (; l < wantL;)
        {
            have[p[ref[l]]]--;
            cnt -= have[p[ref[l]]] == 0 ? 1 : 0;
            l++;
        }
        for (; wantR < r;)
        {
            have[p[ref[r]]]--;
            cnt -= have[p[ref[r]]] == 0 ? 1 : 0;
            r--;
        }
        answer[id] = cnt;
    }
    for (int i = l; i <= r; i++)
    {
        have[p[ref[i]]]--;
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ask.push_back({u, v, i});
    }
    init(1, 0);
    for (auto k : ask)
    {
        wait[gid[std::get<1>(k)]].push_back(k);
    }
    for (auto u : s)
    {
        if (wait[u].empty())
        {
            continue;
        }
        solve(u, wait[u]);
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}