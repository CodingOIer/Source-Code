#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e5 + 5;
class node
{
  public:
    int lc, rc;
    bool accept;
    node()
    {
        lc = 0;
        rc = 0;
        accept = true;
    }
    node(int c)
    {
        lc = c;
        rc = c;
        accept = true;
    }
};
int n, q;
char p[MaxN];
node temp;
node tree[MaxN * 4];
bool lazy[MaxN * 4];
inline node merge(node x, node y)
{
    node res;
    if (x.rc != y.lc && x.accept && y.accept)
    {
        res.accept = true;
    }
    else
    {
        res.accept = false;
    }
    res.lc = x.lc;
    res.rc = y.rc;
    return res;
}
inline void append(node x)
{
    if (temp.lc == -1)
    {
        temp = x;
    }
    else
    {
        temp = merge(temp, x);
    }
}
void downstream(int cur, int s, int t)
{
    if (lazy[cur])
    {
        tree[cur * 2].lc ^= 1;
        tree[cur * 2].rc ^= 1;
        tree[cur * 2 + 1].lc ^= 1;
        tree[cur * 2 + 1].rc ^= 1;
        lazy[cur] = false;
        lazy[cur * 2] ^= 1;
        lazy[cur * 2 + 1] ^= 1;
    }
}
void build(int cur, int s, int t)
{
    if (s == t)
    {
        tree[cur].lc = p[s] - '0';
        tree[cur].rc = p[s] - '0';
        tree[cur].accept = true;
        return;
    }
    int mid = (s + t) / 2;
    build(cur * 2, s, mid);
    build(cur * 2 + 1, mid + 1, t);
    tree[cur] = merge(tree[cur * 2], tree[cur * 2 + 1]);
}
void change(int cur, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        tree[cur].lc ^= 1;
        tree[cur].rc ^= 1;
        lazy[cur] ^= 1;
        return;
    }
    downstream(cur, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(cur * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        change(cur * 2 + 1, mid + 1, t, l, r);
    }
    tree[cur] = merge(tree[cur * 2], tree[cur * 2 + 1]);
}
void query(int cur, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        append(tree[cur]);
        return;
    }
    downstream(cur, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        query(cur * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        query(cur * 2 + 1, mid + 1, t, l, r);
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    scanf("%s", p + 1);
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            change(1, 1, n, l, r);
        }
        else if (op == 2)
        {
            temp.lc = -1;
            query(1, 1, n, l, r);
            printf("%s\n", temp.accept ? "Yes" : "No");
        }
    }
    return 0;
}