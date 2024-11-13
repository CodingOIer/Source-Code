#include <cstdio>
constexpr int MaxN = 1e6 + 5;
class node
{
  public:
    int x;
    node *left, *right;
    node()
    {
        x = 0;
        left = nullptr;
        right = nullptr;
    }
    node(int k)
    {
        x = k;
        left = nullptr;
        right = nullptr;
    }
};
int n, m;
int p[MaxN];
node *root[MaxN];
void build(node *cur, int s, int t)
{
    if (s == t)
    {
        cur->x = p[s];
        return;
    }
    cur->left = new node;
    cur->right = new node;
    int mid = (s + t) / 2;
    build(cur->left, s, mid);
    build(cur->right, mid + 1, t);
}
int query(node *cur, int s, int t, int w)
{
    if (s == t)
    {
        return cur->x;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        return query(cur->left, s, mid, w);
    }
    else
    {
        return query(cur->right, mid + 1, t, w);
    }
}
void change(node *cur, node *last, int s, int t, int w, int val)
{
    if (s == t)
    {
        cur->x = val;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        cur->right = last->right;
        cur->left = new node;
        change(cur->left, last->left, s, mid, w, val);
    }
    else
    {
        cur->left = last->left;
        cur->right = new node;
        change(cur->right, last->right, mid + 1, t, w, val);
    }
}
inline int read()
{
    int res = 0;
    int f = 1;
    char c = '\0';
    for (;;)
    {
        c = getchar();
        if (c == '-')
        {
            f = -1;
        }
        else if ('0' <= c && c <= '9')
        {
            res = res * 10 + c - '0';
            break;
        }
    }
    for (;;)
    {
        c = getchar();
        if ('0' <= c && c <= '9')
        {
            res = res * 10 + c - '0';
        }
        else
        {
            break;
        }
    }
    return res * f;
}
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
    {
        p[i] = read();
    }
    root[0] = new node;
    build(root[0], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int v, op;
        v = read();
        op = read();
        root[i] = new node;
        if (op == 1)
        {
            int x, y;
            x = read();
            y = read();
            change(root[i], root[v], 1, n, x, y);
        }
        else if (op == 2)
        {
            int x;
            x = read();
            printf("%d\n", query(root[v], 1, n, x));
            root[i]->left = root[v]->left;
            root[i]->right = root[v]->right;
        }
    }
    return 0;
}