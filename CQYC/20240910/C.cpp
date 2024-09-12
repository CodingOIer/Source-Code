// 30pts
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, m, q;
bool p[MaxN];
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        p[i] = x % 2 == 1;
    }
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            if (d % 2 == 1)
            {
                for (int j = l; j <= r; j++)
                {
                    p[j] ^= true;
                }
            }
        }
        else if (op == 2)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int ok = 0;
            for (int j = r; j >= l; j--)
            {
                if (ok > 0)
                {
                    ok--;
                    continue;
                }
                if (!p[j])
                {
                    continue;
                }
                if (p[j])
                {
                    ok = m;
                    continue;
                }
            }
            printf("%d\n", ok == m ? 2 : 1);
        }
    }
    return 0;
}