#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, c, q;
int p[MaxN];
bool first[MaxN];
int main()
{
    scanf("%d%d%d", &n, &c, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, c;
            scanf("%d%d%d", &l, &r, &c);
            for (int j = l; j <= r; j++)
            {
                p[j] += c;
            }
        }
        if (op == 2)
        {
            int preLose = 0x3f3f3f3f;
            int l, r;
            scanf("%d%d", &l, &r);
            first[r] = p[r] % 2 == 1;
            if (!first[r])
            {
                preLose = r;
            }
            for (int j = r - 1; j >= l; j--)
            {
                first[j] = false;
                if (preLose - j <= c)
                {
                    first[j] = true;
                }
                if (preLose - j > c && p[j] % 2 == 1)
                {
                    first[j] = true;
                }
                if (!first[j])
                {
                    preLose = j;
                }
            }
            printf("%s\n", first[l] ? "Alice" : "Bob");
        }
    }
    return 0;
}
