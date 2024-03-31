#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, d;
int tree[MaxN * 4];
int query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    int mid = (s + t) / 2;
    if (r <= mid)
    {
        return query(c * 2, s, mid, l, r);
    }
    if (l > mid)
    {
        return query(c * 2 + 1, mid + 1, t, l, r);
    }
    return std::max(query(c * 2, s, mid, l, r), query(c * 2 + 1, mid + 1, t, l, r));
}
void change(int c, int s, int t, int w, int v)
{
    if (s == t)
    {
        tree[c] = v;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change(c * 2, s, mid, w, v);
    }
    else
    {
        change(c * 2 + 1, mid + 1, t, w, v);
    }
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
int main()
{
    scanf("%d%d", &n, &d);
    int last = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        char op = '\0';
        for (; !(op == 'Q' || op == 'A');)
        {
            op = getchar();
        }
        scanf("%d", &x);
        if (op == 'Q')
        {
            last = query(1, 1, n, cnt - x + 1, cnt);
            printf("%d\n", last);
        }
        else if (op == 'A')
        {
            cnt++;
            x = ((long long)(x) + last) % d;
            change(1, 1, n, cnt, x);
        }
    }
    return 0;
}