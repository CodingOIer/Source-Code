#include <algorithm>
#include <cstdio>
constexpr int MaxN = 3e2 + 5;
int n, q;
int p[MaxN];
int dp[MaxN];
int answer[MaxN];
bool check(int x, int g)
{
    if (p[x] > x)
    {
        return false;
    }
    int more, still;
    more = n - x;
    still = more - g;
    if (still >= 0)
    {
        if (x + still <= p[x])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    g -= more;
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
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = std::max(dp[i - 1], dp[std::max(0, i - p[i])] + 1);
    }
    int it = 0;
    for (int i = 1; i <= n; i--)
    {
        int l, r;
        l = 0;
        r = n;
        int res = 0;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (check(mid, i))
            {
            }
        }
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", answer[x]);
    }
    return 0;
}