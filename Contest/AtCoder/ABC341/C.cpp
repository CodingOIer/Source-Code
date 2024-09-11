#include <cstdio>
constexpr int MaxN = 5e2 + 5;
int n;
int h, w;
int answer;
char t[MaxN];
char s[MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &h, &w, &n);
    scanf("%s", t + 1);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int x, y;
            x = i;
            y = j;
            bool accept = true;
            for (int k = 1; k <= n; k++)
            {
                if (s[x][y] != '.')
                {
                    accept = false;
                    break;
                }
                if (t[k] == 'U')
                {
                    x--;
                }
                else if (t[k] == 'D')
                {
                    x++;
                }
                else if (t[k] == 'L')
                {
                    y--;
                }
                else if (t[k] == 'R')
                {
                    y++;
                }
            }
            if (s[x][y] == '.' && accept)
            {
                answer++;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}