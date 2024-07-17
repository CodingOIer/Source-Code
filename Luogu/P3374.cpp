#include <cstdio>
constexpr int MaxN = 5e5 + 5;
int n, m;
long long tree[MaxN];
inline void change(int x, int val)
{
    for (; x <= n; x += x & -x)
    {
        tree[x] += val;
    }
}
inline long long query(int x)
{
    long long res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
inline long long query(int l, int r)
{
    return query(r) - query(l - 1);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        change(i, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, v;
            scanf("%d%d", &x, &v);
            change(x, v);
        }
        else if (op == 2)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(l, r));
        }
    }
    return 0;
}