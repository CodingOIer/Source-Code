#include <algorithm>
#include <cstdio>
constexpr int MaxN = 3e5 + 5;
int n, q;
int p[MaxN];
int dp[MaxN];
int answer[MaxN];
bool check(int x, int g)
{
    int more, still;
    more = n - x;
    still = more - g;
    if (still >= 0)
    {
        if (x + still < p[x])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    g -= more;
    if (p[x] > x)
    {
        return false;
    }
    if (dp[x - p[x]] >= g)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (i >= p[i])
        {
            dp[i] = std::max(dp[i], dp[i - p[i]] + 1);
        }
    }
    int it = 0;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        l = 1;
        r = n;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (check(mid, i - 1))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        answer[i] = r;
    }
    for (int i = 1; i <= q; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d ", answer[x]);
    }
    return 0;
}