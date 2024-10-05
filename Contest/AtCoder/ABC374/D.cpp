#include <algorithm>
#include <cmath>
#include <cstdio>
#include <numeric>
#include <utility>
constexpr int MaxN = 15;
int n, s, t;
int a[MaxN];
int b[MaxN];
int c[MaxN];
int d[MaxN];
int f[MaxN];
inline double dis(int x, int y, int a, int b)
{
    return std::sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
int main()
{
    scanf("%d%d%d", &n, &s, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    }
    std::iota(f + 1, f + 1 + n, 1);
    double answer = 1e18;
    for (;;)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if ((j >> (i - 1)) & 1)
                {
                    std::swap(a[i], c[i]);
                    std::swap(b[i], d[i]);
                }
            }
            double temp = 0;
            int x, y;
            x = 0;
            y = 0;
            for (int i = 1; i <= n; i++)
            {
                temp += dis(x, y, a[f[i]], b[f[i]]) / s;
                x = a[f[i]];
                y = b[f[i]];
                temp += dis(x, y, c[f[i]], d[f[i]]) / t;
                x = c[f[i]];
                y = d[f[i]];
            }
            answer = std::min(answer, temp);
            for (int i = 1; i <= n; i++)
            {
                if ((j >> (i - 1)) & 1)
                {
                    std::swap(a[i], c[i]);
                    std::swap(b[i], d[i]);
                }
            }
        }
        if (!std::next_permutation(f + 1, f + 1 + n))
        {
            break;
        }
    }
    printf("%.12lf\n", answer);
    return 0;
}