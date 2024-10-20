#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
int q[MaxN];
int t[MaxN];
inline bool check(int x)
{
    for (int i = 1; i <= n - 1; i++)
    {
        t[i] = q[i];
    }
    t[n] = x;
    std::sort(t + 1, t + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (t[i] < p[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &q[i]);
    }
    std::sort(p + 1, p + 1 + n);
    int res = -1;
    int l, r;
    l = 1;
    r = 1e9;
    for (; l <= r;)
    {
        int mid = (1ll * l + r) / 2;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d\n", res);
    return 0;
}