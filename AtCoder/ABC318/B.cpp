#include <cstdio>
const int MaxN = 1e2 + 5;
int n;
int answer;
int end_x, end_y;
int start_x, start_y;
int p[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &start_x, &end_x, &start_y, &end_y);
        for (int x = start_x; x <= end_x - 1; x++)
        {
            for (int y = start_y; y <= end_y - 1; y++)
            {
                p[y][x]++;
            }
        }
    }
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            if (p[x][y] >= 1)
            {
                answer++;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}