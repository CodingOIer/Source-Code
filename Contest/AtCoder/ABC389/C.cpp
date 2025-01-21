#include <cstdio>
constexpr int MaxN = 3e5 + 5;
int n, m;
int head, tail;
int len[MaxN];
long long tree[MaxN * 4];
long long lazy[MaxN * 4];
void downstream(int c, int s, int t)
{
    if (lazy[c] != 0)
    {
        int mid = (s + t) / 2;
        tree[c * 2] += (mid - s + 1) * lazy[c];
        tree[c * 2 + 1] += (t - mid) * lazy[c];
        lazy[c * 2] += lazy[c];
        lazy[c * 2 + 1] += lazy[c];
        lazy[c] = 0;
    }
}
void change(int c, int s, int t, int l, int r, long long v)
{
    if (l <= s && t <= r)
    {
        tree[c] += (t - s + 1) * v;
        lazy[c] += v;
        return;
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(c * 2, s, mid, l, r, v);
    }
    if (r > mid)
    {
        change(c * 2 + 1, mid + 1, t, l, r, v);
    }
    tree[c] = tree[c * 2] + tree[c * 2 + 1];
}
long long query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    long long res = 0;
    if (l <= mid)
    {
        res += query(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        res += query(c * 2 + 1, mid + 1, t, l, r);
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    head = 1;
    for (int i = 1; i <= n; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l;
            scanf("%d", &l);
            tail++;
            change(1, 1, n, tail, tail, head == tail ? 0 : query(1, 1, n, tail - 1, tail - 1) + len[tail - 1]);
            len[tail] = l;
        }
        else if (op == 2)
        {
            change(1, 1, n, head + 1, tail, -len[head]);
            head++;
        }
        else if (op == 3)
        {
            int x;
            scanf("%d", &x);
            printf("%lld\n", query(1, 1, n, head + x - 1, head + x - 1));
        }
    }
    return 0;
}
