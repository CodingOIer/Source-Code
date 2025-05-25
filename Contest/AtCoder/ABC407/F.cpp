#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
int lg2[MaxN];
int st[21][MaxN];
long long p[MaxN];
long long cf[MaxN];
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
void change(int c, int s, int t, int w, long long v)
{
    change(c, s, t, w, w, v);
}
void takeOut(int c, int s, int t)
{
    if (s == t)
    {
        cf[s] = tree[c];
        return;
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    takeOut(c * 2, s, mid);
    takeOut(c * 2 + 1, mid + 1, t);
}
int query(int l, int r)
{
    int j = lg2[r - l + 1];
    return std::max(st[j][l], st[j][r - (1 << j) + 1]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        st[0][i] = p[i];
    }
    for (int j = 1; j < 21; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[j][i] = std::max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        l = 1;
        r = i - 1;
        int cl = i;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (query(mid, i - 1) <= p[i])
            {
                cl = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        l = i + 1;
        r = n;
        int cr = i;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (query(i + 1, mid) < p[i])
            {
                cr = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        int c = std::min(i - cl + 1, cr - i + 1);
        change(1, 1, n, 1, c, p[i]);
        change(1, 1, n, c + 1, -p[i] * c);
        if (cl == i || cr == i)
        {
            int more = (cr - cl + 1) - c;
            if (more != 0)
            {
                change(1, 1, n, c + 1, p[i]);
                change(1, 1, n, c + more + 1, -p[i]);
            }
        }
        else
        {
            int less = c;
            int all = cr - cl + 1;
            int alone = (all - c) - less;
            change(1, 1, n, c + 1, less * p[i]);
            change(1, 1, n, c + alone + 1, -p[i] * less);
        }
        takeOut(1, 1, n);
        for (int i = 1; i <= n; i++)
        {
            printf("%lld ", cf[i]);
        }
        printf("\n");
    }
    takeOut(1, 1, n);
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer += cf[i];
        printf("%lld\n", answer);
    }
    return 0;
}