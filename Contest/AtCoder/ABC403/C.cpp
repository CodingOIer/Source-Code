#include <cstdio>
#include <map>
constexpr int MaxN = 2e5 + 5;
int n, m, q;
bool super[MaxN];
std::map<int, bool> map[MaxN];
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            map[x][y] = true;
        }
        if (op == 2)
        {
            int x;
            scanf("%d", &x);
            super[x] = true;
        }
        if (op == 3)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%s\n", super[x] || map[x][y] ? "Yes" : "No");
        }
    }
    return 0;
}