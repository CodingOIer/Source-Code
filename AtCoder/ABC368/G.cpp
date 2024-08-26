#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n, q;
int a[MaxN];
int b[MaxN];
int tree2[MaxN * 4];
long long tree1[MaxN * 4];
void change1(int c, int s, int t, int w)
{
    if (s == t)
    {
        tree1[c] = a[s];
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change1(c * 2, s, mid, w);
    }
    else
    {
        change1(c * 2 + 1, mid + 1, t, w);
    }
    tree1[c] = tree1[c * 2] + tree1[c * 2 + 1];
}
void change2(int c, int s, int t, int w)
{
    if (s == t)
    {
        tree2[c] = b[s] == 1 ? 1 : 0;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change2(c * 2, s, mid, w);
    }
    else
    {
        change2(c * 2 + 1, mid + 1, t, w);
    }
    tree2[c] = tree2[c * 2] + tree2[c * 2 + 1];
}
long long query1(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree1[c];
    }
    int mid = (s + t) / 2;
    long long res = 0;
    if (l <= mid)
    {
        res += query1(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        res += query1(c * 2 + 1, mid + 1, t, l, r);
    }
    return res;
}
int query2(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree2[c];
    }
    int mid = (s + t) / 2;
    int res = 0;
    if (l <= mid)
    {
        res += query2(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        res += query2(c * 2 + 1, mid + 1, t, l, r);
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        change1(1, 1, n, i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        change2(1, 1, n, i);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x] = y;
            change1(1, 1, n, x);
        }
        else if (op == 2)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            change2(1, 1, n, x);
            b[x] = y;
        }
        else if (op == 3)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            long long v = a[x];
            int it = x + 1;
            for (; it <= y;)
            {
                if (b[it] == 1)
                {
                    int l, r;
                    l = it;
                    r = y;
                    int res = 0;
                    for (; l <= r;)
                    {
                        int mid = (l + r) / 2;
                        if (query2(1, 1, n, it, mid) == mid - it + 1)
                        {
                            res = mid;
                            l = mid + 1;
                        }
                        else
                        {
                            r = mid - 1;
                        }
                    }
                    v += query1(1, 1, n, it, res);
                }
                else
                {
                    v = std::max(v + a[it], v * b[it]);
                }
                it++;
            }
            printf("%lld\n", v);
        }
    }
    return 0;
}