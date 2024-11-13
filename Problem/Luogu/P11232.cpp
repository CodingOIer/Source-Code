#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n, m, L, V;
int d[MaxN];
int v[MaxN];
int a[MaxN];
int l[MaxN];
int r[MaxN];
int p[MaxN];
int tree[MaxN];
std::vector<std::tuple<int, int>> vi;
inline void change(int x, int val)
{
    for (; x <= L + 1; x += x & -x)
    {
        tree[x] += val;
    }
}
inline int query(int x)
{
    int res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
inline int query(int l, int r)
{
    return query(r) - query(l - 1);
}
inline int pre(int x)
{
    int l, r;
    l = 1;
    r = m;
    int res = -1;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (p[mid] <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return p[res];
}
void solve()
{
    scanf("%d%d%d%d", &n, &m, &L, &V);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &d[i], &v[i], &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + m);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            if (v[i] > V)
            {
                l[i] = d[i];
                r[i] = L;
            }
            else
            {
                l[i] = r[i] = -1;
            }
        }
        else if (a[i] > 0)
        {
            if (d[i] > p[m])
            {
                l[i] = r[i] = -1;
                continue;
            }
            int deltaX = p[m] - d[i];
            double v2 = sqrt(1.0 * v[i] * v[i] + 2.0 * a[i] * deltaX);
            if (v2 > V)
            {
                r[i] = L;
                int ll, rr;
                ll = 1;
                rr = m;
                int bg = -1;
                for (; ll <= rr;)
                {
                    int mid = (ll + rr) / 2;
                    deltaX = p[mid] - d[i];
                    v2 = sqrt(1.0 * v[i] * v[i] + 2.0 * a[i] * deltaX);
                    if (v2 > V)
                    {
                        rr = mid - 1;
                        bg = mid;
                    }
                    else
                    {
                        ll = mid + 1;
                    }
                }
                l[i] = p[bg];
                r[i] = L;
            }
            else
            {
                l[i] = r[i] = -1;
                continue;
            }
        }
        else if (a[i] < 0)
        {
            if (d[i] > p[m] || v[i] <= V)
            {
                l[i] = r[i] = -1;
                continue;
            }
            int ll, rr;
            ll = 1;
            rr = m;
            int res = -1;
            for (; ll <= rr;)
            {
                int mid = (ll + rr) / 2;
                if (p[mid] >= d[i])
                {
                    res = mid;
                    rr = mid - 1;
                }
                else
                {
                    ll = mid + 1;
                }
            }
            int deltaX = p[res] - d[i];
            double v2 = sqrt(1.0 * v[i] * v[i] + 2.0 * a[i] * deltaX);
            if (v2 <= V || 1.0 * v[i] * v[i] + 2.0 * a[i] * deltaX < 0)
            {
                l[i] = r[i] = -1;
                continue;
            }
            int bg = p[res];
            ll = 1;
            rr = m;
            res = -1;
            for (; ll <= rr;)
            {
                int mid = (ll + rr) / 2;
                deltaX = p[mid] - d[i];
                v2 = sqrt(1.0 * v[i] * v[i] + 2.0 * a[i] * deltaX);
                if (v2 <= V || 1.0 * v[i] * v[i] + 2.0 * a[i] * deltaX < 0)
                {
                    rr = mid - 1;
                }
                else
                {
                    res = mid;
                    ll = mid + 1;
                }
            }
            int ed = res == -1 ? L : p[res];
            l[i] = bg;
            r[i] = ed;
        }
    }
    vi.clear();
    for (int i = 1; i <= n; i++)
    {
        if ((l[i] == -1 && r[i] == -1) || pre(r[i]) < l[i] || l[i] > r[i])
        {
            continue;
        }
        vi.push_back({l[i], r[i]});
    }
    std::sort(vi.begin(), vi.end(), [](const std::tuple<int, int> x, const std::tuple<int, int> &y) -> bool {
        return std::get<1>(x) < std::get<1>(y);
    });
    printf("%zu ", vi.size());
    int need = 0;
    for (auto k : vi)
    {
        int l, r;
        std::tie(l, r) = k;
        if (query(l + 1, r + 1) != 0)
        {
            continue;
        }
        need++;
        change(pre(r) + 1, 1);
    }
    printf("%d\n", m - need);
    memset(tree, 0, sizeof(tree));
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}