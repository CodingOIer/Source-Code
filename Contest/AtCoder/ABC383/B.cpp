#include <algorithm>
#include <cstdio>
#include <cstdlib>
constexpr int MaxN = 1e2 + 5;
int h, w, d;
char s[MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &h, &w, &d);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", s[i] + 1);
    }
    int answer = 0;
    for (int x1 = 1; x1 <= h; x1++)
    {
        for (int y1 = 1; y1 <= w; y1++)
        {
            for (int x2 = 1; x2 <= h; x2++)
            {
                for (int y2 = 1; y2 <= w; y2++)
                {
                    if (s[x1][y1] == '#' || s[x2][y2] == '#')
                    {
                        continue;
                    }
                    int temp = 0;
                    for (int i = 1; i <= h; i++)
                    {
                        for (int j = 1; j <= w; j++)
                        {
                            int di = std::min(abs(x1 - i) + abs(y1 - j), abs(x2 - i) + abs(y2 - j));
                            if (di <= d && s[i][j] == '.')
                            {
                                temp++;
                            }
                        }
                    }
                    answer = std::max(answer, temp);
                }
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
