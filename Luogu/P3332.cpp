#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 5e4 + 5;
class ask
{
  public:
    int op;
    int id;
    int l, r;
    long long x;
    ask()
    {
        l = 0;
        r = 0;
        x = 0;
        op = 0;
        id = 0;
    }
};
int sl;
int n, m;
int tree[MaxN * 4];
int lazy[MaxN * 4];
int answer[MaxN];
long long s[MaxN];
inline int link(long long x)
{
    return std::lower_bound(s + 1, s + 1 + sl, x) - s;
}
inline void downstream(int c, int s, int t)
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
void change(int c, int s, int t, int l, int r, int v)
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
int query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    int res = 0;
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
void solve(int l, int r, std::vector<ask> &q)
{
}
int main()
{
    scanf("%d%d", &n, &m);
    std::vector<ask> query;
    for (int i = 1; i <= m; i++)
    {
        ask temp;
        scanf("%d%d%d%lld", &temp.op, &temp.l, &temp.r, &temp.x);
        temp.id = i;
        s[i] = temp.x;
        query.push_back(temp);
    }
    std::sort(s + 1, s + 1 + m);
    sl = std::unique(s + 1, s + 1 + m) - s - 1;
    return 0;
}