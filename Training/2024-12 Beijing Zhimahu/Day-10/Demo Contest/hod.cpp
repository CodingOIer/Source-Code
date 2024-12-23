#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e6 + 5;
int n, m;
int p[MaxN];
int b[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            p[x] = y;
        }
        else if (op == 2)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            int answer = 0;
            int last = -1;
            int suc = 0;
            last = l;
            suc += p[l] == x ? 1 : 0;
            if (suc >= 1)
            {
                answer = 1;
            }
            for (int j = l + 1; j <= r; j++)
            {
                suc += p[j] == x ? 1 : 0;
                if (p[j] != b[p[j - 1]])
                {
                    for (; last < j; last++)
                    {
                        suc -= p[last] == x ? 1 : 0;
                    }
                }
                if (suc >= 1)
                {
                    answer = std::max(answer, j - last + 1);
                }
            }
            printf("%d\n", answer);
        }
    }
    return 0;
}
