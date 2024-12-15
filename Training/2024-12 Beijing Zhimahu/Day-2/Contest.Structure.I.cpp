#include <cstdio>
constexpr int MaxN = 5e2 + 5;
int h, w;
char s[MaxN][MaxN];
void solve()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= h; i += 3)
    {
        for (int j = 1; j <= w; j++)
        {
            s[i][j] = 'X';
        }
        if (i == h || i + 1 == h)
        {
            continue;
        }
        if (i + 2 == h)
        {
            for (int j = 1; j <= w; j++)
            {
                if (s[i + 2][j] == 'X')
                {
                    s[i + 1][j] = 'X';
                }
            }
            continue;
        }
        bool cover = false;
        for (int j = 1; j <= w && !cover; j++)
        {
            if (s[i + 1][j] == 'X')
            {
                cover = true;
                s[i + 2][j] = 'X';
            }
            else if (s[i + 2][j] == 'X')
            {
                cover = true;
                s[i + 1][j] = 'X';
            }
        }
        if (!cover)
        {
            s[i + 1][1] = 'X';
            s[i + 2][1] = 'X';
        }
    }
    for (int i = 1; i <= h; i++)
    {
        printf("%s\n", s[i] + 1);
    }
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
