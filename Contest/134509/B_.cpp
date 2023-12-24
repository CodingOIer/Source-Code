#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 10, mod = 1e9 + 7;
inline int read()
{
    int c, w = 0, n = 0;
    while ((c = getchar()) < '0' || '9' < c)
        w = c == '-';
    do
        n = n * 10 + c - '0';
    while ('0' <= (c = getchar()) && c <= '9');
    return w ? -n : n;
}
inline int write(int n)
{
    if (n < 0)
        putchar('-'), n = -n;
    if (n > 9)
        write(n / 10);
    putchar(n % 10 + '0');
    return n;
}
long long d[4 * MaxN];
long long lazy[4 * MaxN];
inline void build(long long s, long long t, long long k)
{
    if (s == t)
    {
        d[k] = p[s];
        return;
    }
    long long mid;
    mid = (s + t) >> 1;
    build(s, mid, k << 1);
    build(mid + 1, t, (k << 1) + 1);
    d[k] = d[k << 1] + d[(k << 1) + 1];
}
inline void push_down(long long s, long long t, long long k)
{
    long long mid;
    mid = (s + t) >> 1;
    if (lazy[k] != 0)
    {
        d[k << 1] += (mid - s + 1) * lazy[k];
        d[(k << 1) + 1] += (t - mid) * lazy[k];
        lazy[k << 1] += lazy[k];
        lazy[(k << 1) + 1] += lazy[k];
        lazy[k] = 0;
    }
}
inline void add(long long s, long long t, long long l, long long r, long long k, long long c)
{
    if (l <= s && t <= r)
    {
        d[k] += (t - s + 1) * c;
        lazy[k] += c;
        return;
    }
    push_down(s, t, k);
    long long mid;
    mid = (s + t) >> 1;
    if (l <= mid)
    {
        add(s, mid, l, r, k << 1, c);
    }
    if (r >= mid + 1)
    {
        add(mid + 1, t, l, r, (k << 1) + 1, c);
    }
    d[k] = d[k << 1] + d[(k << 1) + 1];
    return;
}
inline long long sum(long long s, long long t, long long l, long long r, long long k)
{
    if (l <= s && t <= r)
    {
        return d[k];
    }
    push_down(s, t, k);
    long long mid;
    mid = (s + t) >> 1;
    long long res;
    res = 0;
    if (l <= mid)
    {
        res += sum(s, mid, l, r, k << 1);
    }
    if (r >= mid + 1)
    {
        res += sum(mid + 1, t, l, r, (k << 1) + 1);
    }
    return res;
}
class tree
{
  protected:
    struct node
    {
        int l, r;
        int data, lazy;
    } a[maxn << 4];

  public:
    void init(int id, int l, int r, int *p)
    {
        a[id].l = l, a[id].r = r;
        if (l >= r)
        {
            a[id].data = *(p + l);
            return;
        }
        int mid = (l + r) >> 1;
        init(id << 1, l, mid, p);
        init(id << 1 | 1, mid + 1, r, p);
        a[id].data = a[id << 1].data + a[id << 1 | 1].data;
    }
    void down(int id)
    {
        if (!a[id].lazy)
            return;
        a[id].data += a[id].lazy * (a[id].r - a[id].l + 1);
        a[id << 1].lazy += a[id].lazy;
        a[id << 1 | 1].lazy += a[id].lazy;
        a[id].lazy = 0;
    }
    void update(int id)
    {
        a[id].data = a[id << 1].data + a[id << 1].lazy * (a[id << 1].r - a[id << 1].l + 1) + a[id << 1 | 1].data +
                     a[id << 1 | 1].lazy * (a[id << 1 | 1].r - a[id << 1 | 1].l + 1);
    }
    void change(int id, int l, int r, int add)
    {
        if (a[id].l == l && a[id].r == r)
        {
            a[id].lazy += add;
            return;
        }
        down(id);
        if (a[id << 1].r < l)
            change(id << 1 | 1, l, r, add);
        else if (a[id << 1 | 1].l > r)
            change(id << 1, l, r, add);
        else
        {
            change(id << 1, l, a[id << 1].r, add);
            change(id << 1 | 1, a[id << 1 | 1].l, r, add);
        }
        update(id);
    }
    int sum(int id, int l, int r)
    {
        if (l > r)
            return 0;
        if (a[id].l == l && a[id].r == r)
            return a[id].data + a[id].lazy * (a[id].r - a[id].l + 1);
        down(id);
        if (a[id << 1 | 1].l > r)
            return sum(id << 1, l, r);
        if (a[id << 1].r < l)
            return sum(id << 1 | 1, l, r);
        return sum(id << 1, l, a[id << 1].r) + sum(id << 1 | 1, a[id << 1 | 1].l, r);
    }
} sgt;
int n = read(), m = read(), a[maxn], b[maxn];
map<int, int> t;

signed main()
{
    t[0] = t[n + 1] = 0;
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1, l = 1, sum = a[1]; i <= n; ++i, sum += a[i])
        if (a[i] > 0)
        {
            for (; sum <= 0; sum -= a[l], ++l)
                ;
            t[i] = b[i] = i - l + 1, sum = 0, l = i + 1;
        }
    sgt.init(1, 1, n, b);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", sgt.sum(1, i, i));
    }
    while (m--)
    {
        int l = read(), r = read(), ans = 0;
        int ls = t.lower_bound(l)->first, rs = prev(t.upper_bound(r))->first;
        if (ls <= rs && ls - t[ls] + 1 < l)
            ans -= t[ls] - (ls - l + 1);
        write(ans + sgt.sum(1, ls, rs)), puts("");
    }
    return 0;
}