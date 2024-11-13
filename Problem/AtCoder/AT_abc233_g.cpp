#include <cstdio>
#include <cstring>
constexpr int MaxN = 5e1 + 5;
int n;
int dp[MaxN][MaxN][MaxN][MaxN];
inline char getch()
{
    char ch = '\n';
    for (; ch == '\n' || ch == '\r';)
    {
        ch = getchar();
    }
    return ch;
}
int main()
{
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (getch() == '#')
            {
                dp[i][j][i][j] = 1;
            }
            else
            {
                dp[i][j][i][j] = 0;
            }
        }
    }
    return 0;
}