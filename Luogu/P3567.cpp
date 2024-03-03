#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e5 + 5;
class node
{
  public:
    int x;
    int cnt;
    int size;
    node *left, *right;
    node()
    {
        x = 0;
        size = 0;
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
std::pair<int, int> s[MaxN];
void build(node *cur, int s, int t)
{
    if (s == t)
    {
        cur->x = 0;
        cur->size = 1;
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
        cur->x += val;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        cur->right = last->right;
        cur->left = new node;
        change(cur->left, last->left, s, mid, w, val);
        cur->update();
    }
    else
    {
        cur->left = last->left;
        cur->right = new node;
        change(cur->right, last->right, mid + 1, t, w, val);
    }
}
int query(node *cur, node *last, int s, int t, int val)
{
    if (s == t)
    {
        if (cur->x - last->x >= val)
        {
            return s;
        }
        else
        {
            return 0;
        }
    }
    int mid = (s + t) / 2;
    int res = 0;
    if (cur->left->size - last->left->size >= val)
    {
        res = std::max(res, query(cur->left, last->left, s, mid, val));
    }
    if (cur->right->size - last->right->size >= val)
    {
        res = std::max(res, query(cur->right, last->right, mid + 1, t, val));
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    root[0] = new node;
    build(root[0], 1, n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        s[i].first = p[i];
        s[i].second = i;
    }
    std::sort(s + 1, s + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        p[s[i].second] = i;
        link[i] = s[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        root[i] = new node;
        change(root[i], root[i - 1], 1, n, p[i], 1);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", link[query(root[r], root[l - 1], 1, n, (r - l + 2) / 2)]);
    }
    return 0;
}