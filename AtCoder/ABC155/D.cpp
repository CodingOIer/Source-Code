#include <algorithm>
#include <cstdio>
const int MaxN = 2e2 + 5;
long long n, m, k;
long long t[MaxN];
long long p[MaxN];
long long smallNumber(long long x)
{
    long long res;
    res = -1e18;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        l = i + 1;
        r = n;
        for (; l <= r;)
        {
            int mid;
            mid = (l + r) / 2;
            if (p[i] * p[mid] <= x)
            {
                if (x - p[i] * p[mid] < x - res)
                {
                    res = p[i] * p[mid];
                }
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return res;
}
long long whichSmall(long long x)
{
    long long result;
    result = 0;
    long long now;
    now = smallNumber(x);
    for (int i = 1; i <= n; i++)
    {
        int res;
        int l, r;
        res = i;
        l = i + 1;
        r = n;
        for (; l <= r;)
        {
            int mid;
            mid = (l + r) / 2;
            if (p[i] * p[mid] <= now)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        result += res - i;
    }
    return result;
}
int main()
{
    scanf("%lld%lld", &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &t[i]);
    }
    std::sort(t + 1, t + 1 + m);
    n = 1;
    p[1] = t[1];
    for (int i = 2; i <= m; i++)
    {
        if (t[i] != t[i - 1])
        {
            n++;
            p[n] = t[i];
        }
    }
    long long result;
    result = -1e18;
    long long l, r;
    l = -1e18;
    r = 1e18;
    for (; l <= r;)
    {
        long long mid;
        mid = (l + r) / 2;
        if (whichSmall(mid) <= k)
        {
            result = smallNumber(mid);
            l = mid + 1;
        }
        else if (whichSmall(mid) > k)
        {
            r = mid - 1;
        }
    }
    return 0;
}