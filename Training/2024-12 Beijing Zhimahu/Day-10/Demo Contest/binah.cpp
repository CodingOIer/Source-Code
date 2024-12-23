#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
int have[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, y, d, c;
            scanf("%d%d%d%d", &x, &y, &d, &c);
            for (int px = 0; px < d; px++)
            {
                for (int py = 0; px + py < d; py++)
                {
                    have[x + px][y + py] += c;
                }
            }
        }
        else if (op == 2)
        {
            unsigned int answer = 0;
            answer = answer << 2 >> 2;
            int sx, ex, sy, ey;
            scanf("%d%d%d%d", &sx, &ex, &sy, &ey);
            for (int x = sx; x <= ex; x++)
            {
                for (int y = sy; y <= ey; y++)
                {
                    answer += have[x][y];
                }
            }
            printf("%d\n", answer);
        }
    }
    return 0;
}
