#include <cstdio>
#include <map>
const int mod = 1e9 + 7;
const int MaxN = 2e5 + 10;
struct Node
{
    int l, r;
    int data, lazy;
};
Node a[MaxN * 4];
void init(int id, int l, int r, int *p)
{
    a[id].l = l, a[id].r = r;
    if (l >= r)
    {
        a[id].data = *(p + l);
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2, l, mid, p);
    init(id * 2 + 1, mid + 1, r, p);
    a[id].data = a[id * 2].data + a[id * 2 + 1].data;
}
void down(int id)
{
    if (!a[id].lazy)
        return;
    a[id].data += a[id].lazy * (a[id].r - a[id].l + 1);
    a[id * 2].lazy += a[id].lazy;
    a[id * 2 + 1].lazy += a[id].lazy;
    a[id].lazy = 0;
}
void update(int id)
{
    a[id].data = a[id * 2].data + a[id * 2].lazy * (a[id * 2].r - a[id * 2].l + 1) + a[id * 2 + 1].data +
                 a[id * 2 + 1].lazy * (a[id * 2 + 1].r - a[id * 2 + 1].l + 1);
}
void change(int id, int l, int r, int add)
{
    if (a[id].l == l && a[id].r == r)
    {
        a[id].lazy += add;
        return;
    }
    down(id);
    if (a[id * 2].r < l)
    {
        change(id * 2 + 1, l, r, add);
    }
    else if (a[id * 2 + 1].l > r)
    {
        change(id * 2, l, r, add);
    }
    else
    {
        change(id * 2, l, a[id * 2].r, add);
        change(id * 2 + 1, a[id * 2 + 1].l, r, add);
    }
    update(id);
}
int sum(int id, int l, int r)
{
    if (l > r)
        return 0;
    if (a[id].l == l && a[id].r == r)
    {
        return a[id].data + a[id].lazy * (a[id].r - a[id].l + 1);
    }
    down(id);
    if (a[id * 2 + 1].l > r)
    {
        return sum(id * 2, l, r);
    }
    if (a[id * 2].r < l)
    {
        return sum(id * 2 + 1, l, r);
    }
    return sum(id * 2, l, a[id * 2].r) + sum(id * 2 + 1, a[id * 2 + 1].l, r);
}
int n, m;
int p[MaxN], b[MaxN];
int l, r, ans;
std::map<int, int> t;
int main()
{
    scanf("%d%d", &n, &m);
    t[0] = t[n + 1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1, l = 1, sum = p[1]; i <= n; ++i, sum += p[i])
    {
        if (p[i] > 0)
        {
            t[i] = b[i] = i - l + 1;
            sum = 0;
            l = i + 1;
        }
    }
    init(1, 1, n, b);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &l, &r);
        int ls = t.lower_bound(l)->first, rs = prev(t.upper_bound(r))->first;
        if (ls <= rs && ls - t[ls] + 1 < l)
        {
            ans -= t[ls] - (ls - l + 1);
        }
        printf("%d\n", ans + sum(1, ls, rs));
    }
    return 0;
}
