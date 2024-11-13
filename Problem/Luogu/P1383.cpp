#include <cstdio>
constexpr int MaxN = 1e5 + 5;
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
};
int n;
int cnt[MaxN];
node *root[MaxN];
void build(node *cur, int s, int t)
{
    if (s == t)
    {
        return;
    }
    cur->left = new node;
    cur->right = new node;
    int mid = (s + t) / 2;
    build(cur->left, s, mid);
    build(cur->right, mid + 1, t);
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
int main()
{
    scanf("%d", &n);
    root[0] = new node;
    build(root[0], 1, n);
    int v = 0;
    for (int i = 1; i <= n; i++)
    {
        char op = '\0';
        for (; !(op == 'T' || op == 'U' || op == 'Q');)
        {
            op = getchar();
        }
        if (op == 'T')
        {
            char c = ' ';
            for (; c == ' ';)
            {
                c = getchar();
            }
            v++;
            cnt[v] = cnt[v - 1];
            cnt[v]++;
            root[v] = new node;
            change(root[v], root[v - 1], 1, n, cnt[v], int(c));
        }
        else if (op == 'U')
        {
            int x;
            scanf("%d", &x);
            v++;
            cnt[v] = cnt[v - x - 1];
            root[v] = new node;
            root[v]->left = root[v - x - 1]->left;
            root[v]->right = root[v - x - 1]->right;
        }
        else if (op == 'Q')
        {
            int x;
            scanf("%d", &x);
            printf("%c\n", char(query(root[v], 1, n, x)));
        }
    }
    return 0;
}