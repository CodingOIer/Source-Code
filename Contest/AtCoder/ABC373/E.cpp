#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m;
int w[MaxN];
long long k;
long long p[MaxN];
long long s[MaxN];
long long t[MaxN];
std::vector<std::tuple<long long, int>> v;
long long sum(int l, int r, int me)
{
    long long res = 0;
    if (w[me] <= l)
    {
        l++;
        r++;
    }
    else if (l <= w[me] && w[me] <= r)
    {
        r++;
        res -= p[me];
    }
    return res + t[r] - t[l - 1];
}
inline bool check(long long x, int to, long long more)
{
    int l, r;
    l = 1;
    r = n;
    int res = -1;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (std::get<0>(v[mid - 1]) <= x)
        {
            l = mid + 1;
            res = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    int rk = n - res + 1;
    if (rk > m)
    {
        return false;
    }
    long long need = (m - rk + 1) * (x + 1) - sum(rk, m, to);
    return need > more;
}
int main()
{
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        v.push_back({p[i], i});
        k -= p[i];
    }
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        w[std::get<1>(v[i - 1])] = i;
        t[i] = t[i - 1] + std::get<0>(v[i - 1]);
    }
    std::reverse(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        long long l, r;
        l = 0;
        r = k;
        long long res = -1;
        for (; l <= r;)
        {
            long long mid = (l + r) / 2;
            if (check(p[i] + mid, i, k - mid))
            {
                r = mid - 1;
                res = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%lld ", res);
    }
    return 0;
}