#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <tuple>
#include <utility>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int block;
int n, m, q;
int p[MaxN];
int cp[MaxN];
int fi[MaxN];
int se[MaxN];
int fil[MaxN];
int cnt[MaxN];
int xid[MaxN];
int toColor[MaxN];
int befColor[MaxN];
int st[22][2 * MaxN];
bool pass[MaxN];
long long k[MaxN];
long long w[MaxN];
long long answer[MaxN];
std::vector<int> ro;
std::vector<int> ou;
std::vector<int> g[MaxN];
std::vector<std::tuple<int, int, int, int, int>> v;
void dfs(int u, int f)
{
    ro.push_back(u);
    ou.push_back(u);
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
        ou.push_back(u);
    }
    ro.push_back(u);
}
int topSt(int x, int y)
{
    return fil[x] < fil[y] ? x : y;
}
int lca(int x, int y)
{
    int l, r;
    l = fil[x];
    r = fil[y];
    if (l > r)
    {
        std::swap(l, r);
    }
    int j = log2(r - l + 1);
    return topSt(st[j][l], st[j][r - (1 << j) + 1]);
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    block = std::pow(n, 2.0 / 3);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &k[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &w[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        cp[i] = p[i];
    }
    ro.push_back(0);
    ou.push_back(0);
    dfs(1, 0);
    for (int i = 1; i <= 2 * n; i++)
    {
        se[ro[i]] = fi[ro[i]] == 0 ? 0 : i;
        fi[ro[i]] = fi[ro[i]] == 0 ? i : fi[ro[i]];
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        fil[ou[i]] = fil[ou[i]] == 0 ? i : fil[ou[i]];
        st[0][i] = ou[i];
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= 2 * n - 1; i++)
        {
            st[j][i] = topSt(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    int ver = 0;
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 0)
        {
            ver++;
            scanf("%d%d", &xid[ver], &toColor[ver]);
            befColor[ver] = cp[xid[ver]];
            cp[xid[ver]] = toColor[ver];
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (fi[x] > fi[y])
            {
                std::swap(x, y);
            }
            int lc = lca(x, y);
            if (lc == x)
            {
                x = fi[x];
                y = fi[y];
                lc = 0;
            }
            else
            {
                x = se[x];
                y = fi[y];
            }
            v.push_back({ver, x, y, i, lc});
        }
    }
    std::sort(v.begin(), v.end(),
              [](const std::tuple<int, int, int, int, int> &x, const std::tuple<int, int, int, int, int> &y) -> bool {
                  return std::get<0>(x) / block == std::get<0>(y) / block
                             ? std::get<1>(x) / block == std::get<1>(y) / block
                                   ? (std::get<2>(x) == std::get<2>(y) ? false : std::get<1>(x) / block % 2 == 1) ^
                                         (std::get<2>(x) < std::get<2>(y))
                                   : std::get<1>(x) / block < std::get<1>(y) / block
                             : std::get<0>(x) / block < std::get<0>(y) / block;
              });
    int l, r, time;
    time = 0;
    l = 1;
    r = 0;
    long long res = 0;
    for (const auto &[wantTime, wantL, wantR, id, fix] : v)
    {
        for (; wantL < l;)
        {
            l--;
            pass[ro[l]] ^= true;
            if (pass[ro[l]])
            {
                cnt[p[ro[l]]]++;
                res += k[p[ro[l]]] * w[cnt[p[ro[l]]]];
            }
            else
            {
                res -= k[p[ro[l]]] * w[cnt[p[ro[l]]]];
                cnt[p[ro[l]]]--;
            }
        }
        for (; r < wantR;)
        {
            r++;
            pass[ro[r]] ^= true;
            if (pass[ro[r]])
            {
                cnt[p[ro[r]]]++;
                res += k[p[ro[r]]] * w[cnt[p[ro[r]]]];
            }
            else
            {
                res -= k[p[ro[r]]] * w[cnt[p[ro[r]]]];
                cnt[p[ro[r]]]--;
            }
        }
        for (; l < wantL;)
        {
            pass[ro[l]] ^= true;
            if (pass[ro[l]])
            {
                cnt[p[ro[l]]]++;
                res += k[p[ro[l]]] * w[cnt[p[ro[l]]]];
            }
            else
            {
                res -= k[p[ro[l]]] * w[cnt[p[ro[l]]]];
                cnt[p[ro[l]]]--;
            }
            l++;
        }
        for (; r > wantR;)
        {
            pass[ro[r]] ^= true;
            if (pass[ro[r]])
            {
                cnt[p[ro[r]]]++;
                res += k[p[ro[r]]] * w[cnt[p[ro[r]]]];
            }
            else
            {
                res -= k[p[ro[r]]] * w[cnt[p[ro[r]]]];
                cnt[p[ro[r]]]--;
            }
            r--;
        }
        for (; time < wantTime;)
        {
            time++;
            if (pass[xid[time]])
            {
                res -= k[p[xid[time]]] * w[cnt[p[xid[time]]]];
                cnt[p[xid[time]]]--;
                cnt[toColor[time]]++;
                res += k[toColor[time]] * w[cnt[toColor[time]]];
            }
            p[xid[time]] = toColor[time];
        }
        for (; wantTime < time;)
        {
            if (pass[xid[time]])
            {
                res -= k[p[xid[time]]] * w[cnt[p[xid[time]]]];
                cnt[p[xid[time]]]--;
                cnt[befColor[time]]++;
                res += k[befColor[time]] * w[cnt[befColor[time]]];
            }
            p[xid[time]] = befColor[time];
            time--;
        }
        if (fix != 0)
        {
            pass[fix] ^= true;
            if (pass[fix])
            {
                cnt[p[fix]]++;
                res += k[p[fix]] * w[cnt[p[fix]]];
            }
            else
            {
                res -= k[p[fix]] * w[cnt[p[fix]]];
                cnt[p[fix]]--;
            }
        }
        answer[id] = res;
        if (fix != 0)
        {
            pass[fix] ^= true;
            if (pass[fix])
            {
                cnt[p[fix]]++;
                res += k[p[fix]] * w[cnt[p[fix]]];
            }
            else
            {
                res -= k[p[fix]] * w[cnt[p[fix]]];
                cnt[p[fix]]--;
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        if (answer[i] == 0)
        {
            continue;
        }
        printf("%lld\n", answer[i]);
    }
    return 0;
}
