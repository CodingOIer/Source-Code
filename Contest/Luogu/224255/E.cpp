#include <cstdio>
#include <map>
int n, m, k;
std::map<int, std::map<int, char>> s;
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((n / 2 - i) * 2 + 2 <= k)
            {
                s[i][j] = '#';
            }
            else
            {
                s[i][j] = '.';
            }
        }
        int l = (n / 2 + 1) - i + 1;
        l = n / 2 + 1 - l + 1;
        if (l >= 1)
        {
            for (int j = m - n / 2; j <= m - n / 2 + l - 1; j++)
            {
                s[i][j] = '#';
            }
            for (int j = m - n / 2 + l; j <= m; j++)
            {
                s[i][j] = '.';
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i <= n / 2 + 1)
        {
            for (int j = 1; j <= m; j++)
            {
                printf("%c", s[i][j]);
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                printf("%c", s[n - i + 1][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
