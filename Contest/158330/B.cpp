#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int n, m;
char s[MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = s[i][j] == '#' ? '\0' : s[i][j];
        }
    }
    char first, second;
    first = '\0';
    second = '\0';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x, y;
            x = s[i][j];
            y = std::max({s[i + 1][j], s[i - 1][j], s[i][j + 1], s[i][j - 1]});
            if (x > first)
            {
                first = x;
                second = y;
            }
            else if (x == first && y > second)
            {
                second = y;
            }
        }
    }
    if (second != '\0' && first != second)
    {
        printf("%c%c\n", first, second);
    }
    else
    {
        printf("%c\n", first);
    }
    return 0;
}