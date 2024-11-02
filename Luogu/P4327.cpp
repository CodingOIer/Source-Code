#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e3 + 5;
int n;
char s[MaxN];
char sc[MaxN][MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            continue;
        }
        int x, y;
        x = 3;
        y = 4 * i - 1;
        sc[x][y] = s[i];
        sc[x][y - 2] = '#';
        sc[x][y + 2] = '#';
        sc[x + 1][y - 1] = '#';
        sc[x - 1][y - 1] = '#';
        sc[x + 1][y + 1] = '#';
        sc[x - 1][y + 1] = '#';
        sc[x - 2][y] = '#';
        sc[x + 2][y] = '#';
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 != 0)
        {
            continue;
        }
        int x, y;
        x = 3;
        y = 4 * i - 1;
        sc[x][y] = s[i];
        sc[x][y - 2] = '*';
        sc[x][y + 2] = '*';
        sc[x + 1][y - 1] = '*';
        sc[x - 1][y - 1] = '*';
        sc[x + 1][y + 1] = '*';
        sc[x - 1][y + 1] = '*';
        sc[x - 2][y] = '*';
        sc[x + 2][y] = '*';
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 4 * n + 1; j++)
        {
            printf("%c", sc[i][j] == '\0' ? '.' : sc[i][j]);
        }
        printf("\n");
    }
    return 0;
}