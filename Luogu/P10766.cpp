#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e6 + 5;
int n;
int p[MaxN];
int w[MaxN];
int dp[3][MaxN];
char s[MaxN];
char t[MaxN];
inline int gs(int x, int i)
{
    return i == 2 ? x : i;
}
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = s[i] == '1' ? 1 : 0;
        w[i] = t[i] == '1' ? 1 : 0;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[j][i] = n;
        }
    }
    dp[2][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bool rev = (i == 1 ? false : gs(p[i - 1], j) ^ w[i - 1]);
            for (int k = 0; k < 3; k++)
            {
                bool to = (gs(p[i], k)) ^ w[i];
                dp[k][i] = std::min(dp[k][i], dp[j][i - 1] + (k != 2 && j != k ? 1 : 0) + (!rev && to ? 1 : 0));
            }
        }
    }
    printf("%d\n", std::min({dp[0][n], dp[1][n], dp[2][n]}));
    return 0;
}