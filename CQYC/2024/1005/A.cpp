// 100
#include <algorithm>
#include <cstdio>
#include <utility>
constexpr int MaxN = 5e5 + 5;
int n, m;
int k, q;
int a[MaxN];
int b[MaxN];
long long cur;
long long v[MaxN];
long long s1[MaxN];
long long s2[MaxN];
inline void change(int apper)
{
    cur -= apper;
}
inline void change(int l, int r, int apper)
{
    if (l > r)
    {
        std::swap(l, r);
    }
    change((r - l + 1) % 2 == 0 ? 0 : l % 2 == 1 ? apper : -apper);
}
inline long long query()
{
    int l, r;
    l = 1;
    r = k;
    int res = 0;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (v[mid] <= cur)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res == 0 ? v[res + 1] - cur : res == k ? cur - v[res] : std::min(cur - v[res], v[res + 1] - cur);
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    k = m - n + 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        s1[i] = s1[i - 1];
        s2[i] = s2[i - 1];
        if (i % 2 == 1)
        {
            s1[i] += b[i];
        }
        else
        {
            s2[i] += b[i];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        v[i] = -(i % 2 == 1 ? (s1[i + n - 1] - s1[i - 1]) - (s2[i + n - 2] - s2[i])
                            : (s2[i + n - 1] - s2[i - 1]) - (s1[i + n - 2] - s1[i]));
    }
    std::sort(v + 1, v + 1 + k);
    for (int i = 1; i <= n; i++)
    {
        change(i, i, a[i]);
    }
    printf("%lld\n", query());
    for (int i = 1; i <= q; i++)
    {
        int l, r, v;
        scanf("%d%d%d", &l, &r, &v);
        change(l, r, v);
        printf("%lld\n", query());
    }
    return 0;
}