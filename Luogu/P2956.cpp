#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int h, w, n;
bool f[MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int x = x1; x <= x2; x++)
        {
            for (int y = y1; y <= y2; y++)
            {
                f[x][y] = true;
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            answer += f[i][j] ? 1 : 0;
        }
    }
    printf("%d\n", answer);
    return 0;
}