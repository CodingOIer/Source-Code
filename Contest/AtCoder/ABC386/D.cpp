#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m;
int x[MaxN];
int y[MaxN];
int tree[MaxN * 4];
int lazy[MaxN * 4];
char color[MaxN];
std::vector<int> vx;
std::vector<int> vy;
void build(int c, int s, int t)
{
    if (s == t)
    {
        tree[c] = 0;
        lazy[c] = 0;
        return;
    }
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
void downstream(int c)
{
    if (lazy[c] != 0)
    {
        tree[c * 2] = std::max(tree[c * 2], lazy[c]);
        tree[c * 2 + 1] = std::max(tree[c * 2 + 1], lazy[c]);
        lazy[c * 2] = std::max(lazy[c * 2], lazy[c]);
        lazy[c * 2 + 1] = std::max(lazy[c * 2 + 1], lazy[c]);
        lazy[c] = 0;
    }
}
void change(int c, int s, int t, int l, int r, int val)
{
    if (l <= s && t <= r)
    {
        tree[c] = std::max(tree[c], val);
        lazy[c] = std::max(lazy[c], val);
        return;
    }
    downstream(c);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
int query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    downstream(c);
    int mid = (s + t) / 2;
    int res = 0;
    if (l <= mid)
    {
        res = std::max(res, query(c * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        res = std::max(res, query(c * 2 + 1, mid + 1, t, l, r));
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    n = 2e5;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        scanf(" ");
        scanf("%c", &color[i]);
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    std::sort(vx.begin(), vx.end());
    std::sort(vy.begin(), vy.end());
    vx.erase(std::unique(vx.begin(), vx.end()), vx.end());
    vy.erase(std::unique(vy.begin(), vy.end()), vy.end());
    for (int i = 1; i <= m; i++)
    {
        x[i] = std::lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin() + 1;
        y[i] = std::lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin() + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 'B')
        {
            change(1, 1, n, 1, x[i], y[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 'W')
        {
            if (query(1, 1, n, x[i], n) >= y[i])
            {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
