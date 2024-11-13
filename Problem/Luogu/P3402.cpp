#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
constexpr int MaxM = 2e5 + 5;
class node
{
  public:
    int x;
    int size;
    node *left, *right;
    node()
    {
        x = 0;
        size = 1;
        left = nullptr;
        right = nullptr;
    }
    node(int k)
    {
        x = k;
        size = 1;
        left = nullptr;
        right = nullptr;
    }
};
int n, m;
node *root[MaxM];
void build(node *cur, int s, int t)
{
    if (s == t)
    {
        cur->x = s;
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
int querySize(node *cur, int s, int t, int w)
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
void change(node *cur, node *last, int s, int t, int w, int val, int size)
{
    if (s == t)
    {
        cur->x = val;
        cur->size = size;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        cur->right = last->right;
        cur->left = new node;
        change(cur->left, last->left, s, mid, w, val, size);
    }
    else
    {
        cur->left = last->left;
        cur->right = new node;
        change(cur->right, last->right, mid + 1, t, w, val, size);
    }
}
int find(int v, int x)
{
    if (query(root[v], 1, n, x) == x)
    {
        return x;
    }
    return find(v, query(root[v], 1, n, x));
}
int findSize(int v, int x)
{
    if (query(root[v], 1, n, x) == x)
    {
        return querySize(root[v], 1, n, x);
    }
    return find(v, query(root[v], 1, n, x));
}
int main()
{
    scanf("%d%d", &n, &m);
    root[0] = new node;
    build(root[0], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        root[i] = new node;
        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            int fx, fy;
            fx = find(i - 1, x);
            fy = find(i - 1, y);
            int sx, sy;
            sx = findSize(i - 1, x);
            sy = findSize(i - 1, y);
            if (sx < sy)
            {
                change(root[i], root[i - 1], 1, n, fy, fx, sx);
            }
            else
            {
                change(root[i], root[i - 1], 1, n, fx, fy, sy);
            }
        }
        else if (op == 2)
        {
            int x;
            scanf("%d", &x);
            root[i]->left = root[x]->left;
            root[i]->right = root[x]->right;
        }
        else if (op == 3)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (find(i - 1, x) == find(i - 1, y))
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
            root[i]->left = root[i - 1]->left;
            root[i]->right = root[i - 1]->right;
        }
    }
    return 0;
}