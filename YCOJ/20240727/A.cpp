#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e3 + 5;
int n, m;
int p[MaxN][MaxN];
int answer[MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    memset(answer, 0x3f, sizeof(answer));
    answer[1][1] = 0;
    for (int l = 2; l <= n + m; l++)
    {
        for (int x = std::max(1, l - m); x <= std::min(l - 1, n); x++)
        {
            int y = l - x;
            if (p[x][y] == 1)
            {
                answer[x][y]++;
            }
            answer[x + 1][y] = std::min(answer[x + 1][y], answer[x][y] - (p[x][y] == 1 && p[x + 1][y] == 1 ? 1 : 0));
            answer[x][y + 1] = std::min(answer[x][y + 1], answer[x][y] - (p[x][y] == 1 && p[x][y + 1] == 1 ? 1 : 0));
        }
    }
    printf("%d\n", answer[n][m]);
    return 0;
}