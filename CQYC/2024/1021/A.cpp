// ~ 100

#include <csignal>
#include <cstdio>
constexpr int MaxN = 1e6 + 5;
constexpr long long Mod = 998'244'353;
int n, q;
int result;
int p[MaxN];
int t[MaxN];
int sum[5][MaxN];
int answer[15][15];
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res *= x;
            res %= Mod;
        }
        y >>= 1;
        x *= x;
        x %= Mod;
    }
    return res;
}
void dfs(int u, int l, int r)
{
    if (u > r)
    {
        for (int i = l; i <= r; i++)
        {
            for (int j = i + 1; j <= r; j++)
            {
                for (int k = j + 1; k <= r; k++)
                {
                    if ((j - i >= 2 || k - j >= 2) &&
                        (t[i] + t[j] + t[k] == 6 && (t[i] == 1 || t[j] == 1 || t[k] == 1)))
                    {
                        return;
                    }
                }
            }
        }
        result++;
        return;
    }
    if (p[u] == 0)
    {
        for (int i = 1; i <= 3; i++)
        {
            t[u] = i;
            dfs(u + 1, l, r);
        }
    }
    else
    {
        t[u] = p[u];
        dfs(u + 1, l, r);
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        sum[0][i] = sum[0][i - 1];
        sum[1][i] = sum[1][i - 1];
        sum[2][i] = sum[2][i - 1];
        sum[3][i] = sum[3][i - 1];
        sum[p[i]][i]++;
    }
    if (n <= 6)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                result = 0;
                dfs(i, i, j);
                answer[i][j] = result;
            }
        }
        for (int i = 1; i <= q; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", answer[l][r]);
        }
        return 0;
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r - l <= 4)
        {
            result = 0;
            dfs(l, l, r);
            printf("%d\n", result);
        }
        else
        {
            int dis = (sum[1][r] - sum[1][l - 1] == 0 ? 1 : 0) + (sum[2][r] - sum[2][l - 1] == 0 ? 1 : 0) +
                      (sum[3][r] - sum[3][l - 1] == 0 ? 1 : 0);
            if (dis == 0)
            {
                printf("%d\n", 0);
            }
            else if (dis == 1)
            {
                printf("%lld\n", fsp(2, sum[0][r] - sum[0][l - 1]));
            }
            else if (dis == 2)
            {
                printf("%lld\n", (2 * fsp(2, sum[0][r] - sum[0][l - 1]) - 1) % Mod);
            }
            else if (dis == 3)
            {
                printf("%lld\n", (3 * fsp(2, sum[0][r] - sum[0][l - 1]) - 3) % Mod);
            }
        }
    }
    return 0;
}