#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e4 + 5;
int n, m, w;
int c[MaxN];
int d[MaxN];
int f[MaxN];
int dp[MaxN];
int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
inline void merge(int x, int y)
{
    f[find(y)] = find(x);
}
int main()
{
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &c[i], &d[i]);
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        merge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (find(i) != i)
        {
            c[find(i)] += c[i];
            d[find(i)] += d[i];
            c[i] = 0x3f3f3f3f;
            d[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 0x3f3f3f3f)
        {
            continue;
        }
        else
        {
            for (int j = w; j >= c[i]; j--)
            {
                dp[j] = std::max(dp[j], dp[j - c[i]] + d[i]);
            }
        }
    }
    printf("%d\n", dp[w]);
    return 0;
}