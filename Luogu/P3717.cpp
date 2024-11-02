#include <cmath>
#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, m, r;
int x[MaxN];
int y[MaxN];
inline double dis(int x1, int y1, int x2, int y2)
{
    return std::sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
}
int main()
{
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            bool f = false;
            for (int k = 1; k <= m; k++)
            {
                if (dis(i, j, x[k], y[k]) <= r)
                {
                    f = true;
                    break;
                }
            }
            answer += f ? 1 : 0;
        }
    }
    printf("%d\n", answer);
    return 0;
}