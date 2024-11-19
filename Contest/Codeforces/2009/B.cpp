#include <cstdio>
constexpr int MaxN = 5e2 + 5;
int n;
char s[MaxN][5];
inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf(" ");
        scanf("%s", s[i] + 1);
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (s[i][j] == '#')
            {
                printf("%d ", j);
            }
        }
    }
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
