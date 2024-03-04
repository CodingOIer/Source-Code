#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
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
    }
    void update()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + x;
    }
};
int m, n;
int s_len;
int s[MaxN];
node *root[MaxN];
std::vector<int> add[MaxN];
int link(int x)
{
    if (x >= 0)
    {
        return std::lower_bound(s + 1, s + 1 + s_len, x) - s;
    }
    else
    {
        return -link(-x);
    }
}
int find(int x)
{
    if (x >= 0)
    {
        return s[x];
    }
    else
    {
        return -find(-x);
    }
}
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
        cur->x += val;
        cur->update();
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
        cur->update();
    }
}
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add[x].push_back(z);
        add[y + 1].push_back(-z);
        s[i] = z;
    }
    std::sort(s + 1, s + 1 + m);
    s_len = std::unique(s + 1, s + 1 + m) - s;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j < int(add[i].size()); j++)
        {
            add[i][j] = link(add[i][j]);
        }
    }
    root[0] = new node;
    build(root[0], 1, s_len);
    for (int i = 1; i <= n + 1; i++)
    {
        root[i] = new node;
        for (int j = 0; j = int(add[i].size()); j++)
        {
            int w = link(add[i][j]);
            if (w > 0)
            {
                change(root[i], root[i - 1], 1, n, w, 1);
            }
            else
            {
                change(root[i], root[i - 1], 1, n, w, -1);
            }
        }
    }
    long long pre = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        long long a, b, c;
        scanf("%d%lld%lld%lld", &x, &a, &b, &c);
        int k = 1 + (a * pre + b) % c;
    }
    return 0;
}