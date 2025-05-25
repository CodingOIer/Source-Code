#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int n, m, q;
int p[MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
        }
        p[i][m + 1] = 0x3f3f3f3f;
    }
    for (int i = 1; i <= q; i++)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            int k;
            scanf("%d", &k);
            int l, r;
            l = 1;
            r = m + 1;
            for (; l <= r;)
            {
                int mid = (l + r) / 2;
                int need = k - (m - mid + 1);
                int less = std::upper_bound(p[y] + 1, p[y] + 1 + m, p[x][mid]) - p[y];
                less = m - less + 1;
                if (need < less)
                {
                    l = mid + 1;
                    continue;
                }
                if (need == less)
                {
                    printf("%d\n", p[x][mid]);
                    break;
                }
                int is = std::lower_bound(p[y] + 1, p[y] + 1 + m, p[x][mid]) - p[y];
                is = m - is + 1;
                if (less != is)
                {
                    if (need <= is)
                    {
                        printf("%d\n", p[x][mid]);
                        break;
                    }
                }
                int more = std::upper_bound(p[y] + 1, p[y] + 1 + m, p[x][mid - 1]) - p[y];
                more = m - more + 1;
                if (more != is)
                {
                    if (need <= more)
                    {
                        printf("%d\n", p[y][m - need + 1]);
                        break;
                    }
                }
                r = mid - 1;
            }
        }
        else if (op == 2)
        {
            int c = std::upper_bound(p[x] + 1, p[x] + 1 + m, y) - p[x];
            if (c != 1)
            {
                p[x][c - 1] = y;
            }
        }
    }
    return 0;
}
