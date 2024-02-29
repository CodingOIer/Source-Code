#include <cstdio>
constexpr int MaxN = 8e4 + 5;
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
    int mid = (s + t) / 2;
    cur->left = new node;
    cur->right = new node;
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
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = cnt[i - 1];
        root[i] = new node;
        char op = '\0';
        for (; !(op == 'a' || op == 's' || op == 't');)
        {
            op = getchar();
        }
        if (op == 'a')
        {
            int x;
            scanf("%d", &x);
            cnt[i]++;
            change(root[i], root[i - 1], 1, n, cnt[i], x);
        }
        else if (op == 's')
        {
            cnt[i]--;
            root[i]->left = root[i - 1]->left;
            root[i]->right = root[i - 1]->right;
        }
        else if (op == 't')
        {
            int x;
            scanf("%d", &x);
            root[i]->left = root[x - 1]->left;
            root[i]->right = root[x - 1]->right;
            cnt[i] = cnt[x - 1];
        }
        if (cnt[i] == 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", query(root[i], 1, n, cnt[i]));
        }
    }
    return 0;
}