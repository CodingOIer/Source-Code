#include <cstdio>
typedef __int128 int128;
namespace std
{
int128 max(int128 x, int128 y)
{
    return x > y ? x : y;
}
}; // namespace std
constexpr int MaxN = 8e1 + 5;
int n, m;
int p[MaxN][MaxN];
int128 dp[MaxN][MaxN][MaxN];
void printInt128(int128 x, bool first = true)
{
    if (x == 0)
    {
        if (first)
        {
            printf("0");
        }
        return;
    }
    printInt128(x / 10, false);
    printf("%c", int(x % 10) ^ 48);
}
int128 fsp(int128 x, int128 y)
{
    int128 res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res *= x;
        }
        y >>= 1;
        x *= x;
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int cur = 1; cur <= n; cur++)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[cur][i][i] = p[cur][i] * fsp(2, m);
        }
        for (int len = 2; len <= m; len++)
        {
            for (int i = 1; i <= m - len + 1; i++)
            {
                dp[cur][i][i + len - 1] = std::max(dp[cur][i][i + len - 2] + p[cur][i + len - 1] * fsp(2, m - len + 1),
                                                   p[cur][i] * fsp(2, m - len + 1) + dp[cur][i + 1][i + len - 1]);
            }
        }
    }
    int128 answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer += dp[i][1][m];
    }
    printInt128(answer);
    printf("\n");
    return 0;
}
