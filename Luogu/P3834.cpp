#include <algorithm>
#include <cstdio>
#include <set>
constexpr int MaxN = 2e5 + 5;
class node
{
  public:
    int x;
    int size;
    node *left, *right;
    node()
    {
        x = 0;
        size = 0;
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
    void update()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + x;
    }
};
int n, m;
int p[MaxN];
int link[MaxN];
node *root[MaxN];
std::pair<int, int> sort[MaxN];
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
void change(node *cur, node *before, int s, int t, int w, int val)
{
    if (s == t)
    {
        cur->x += val;
        cur->update();
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        cur->right = before->right;
        cur->left = new node;
        change(cur->left, before->left, s, mid, w, val);
    }
    else
    {
        cur->left = before->left;
        cur->right = new node;
        change(cur->right, before->right, mid + 1, t, w, val);
    }
    cur->update();
}
int query(node *cur, node *last, int s, int t, int w)
{
    if (s == t)
    {
        return s;
    }
    int mid = (s + t) / 2;
    int left_son_size = cur->left->size - last->left->size;
    if (w <= left_son_size)
    {
        return query(cur->left, last->left, s, mid, w);
    }
    else
    {
        return query(cur->right, last->right, mid + 1, t, w - left_son_size);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        sort[i].first = p[i];
        sort[i].second = i;
    }
    std::sort(sort + 1, sort + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        p[sort[i].second] = i;
        link[i] = sort[i].first;
    }
    root[0] = new node;
    build(root[0], 1, n);
    for (int i = 1; i <= n; i++)
    {
        root[i] = new node;
        change(root[i], root[i - 1], 1, n, p[i], 1);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        printf("%d\n", link[query(root[y], root[x - 1], 1, n, k)]);
    }
    return 0;
}