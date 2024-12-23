#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, m;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        for (int j = l; j <= r; j++)
        {
            x = std::max(x, p[j] - x);
        }
        printf("%d\n", x);
    }
    return 0;
}
