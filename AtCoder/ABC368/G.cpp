#include <algorithm>
#include <cstdio>
#include <set>
constexpr int MaxN = 1e5 + 5;
int n, m;
int a[MaxN];
int b[MaxN];
long long tree[MaxN];
std::set<int> set;
void change(int x, long long val)
{
    for (; x <= n; x += x & -x)
    {
        tree[x] += val;
    }
}
long long query(int x)
{
    long long res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
long long query(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    return query(r) - query(l - 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        change(i, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        if (b[i] != 1)
        {
            set.insert(i);
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            change(x, -a[x]);
            a[x] = y;
            change(x, a[x]);
        }
        else if (op == 2)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (b[x] != 1)
            {
                set.erase(x);
            }
            b[x] = y;
            if (b[x] != 1)
            {
                set.insert(x);
            }
        }
        else if (op == 3)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            if (set.empty())
            {
                printf("%lld\n", query(l, r));
            }
            long long val = 0;
            int it = l;
            for (; it <= r;)
            {
                val = std::max(val + a[it], val * b[it]);
                if (it == r)
                {
                    break;
                }
                auto next = set.upper_bound(it);
                if (next == set.end())
                {
                    val += query(it + 1, r);
                    break;
                }
                if (*next <= r)
                {
                    val += query(it + 1, *next - 1);
                    it = *next;
                }
                else
                {
                    val += query(it + 1, r);
                    break;
                }
            }
            printf("%lld\n", val);
        }
    }
    return 0;
}