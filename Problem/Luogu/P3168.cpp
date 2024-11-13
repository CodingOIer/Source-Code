#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
class node
{
  public:
    int x;
    int size;
    long long sum;
    node *left, *right;
    node()
    {
        x = 0;
        sum = 0;
        size = 0;
        left = nullptr;
        right = nullptr;
    }
    void update()
    {
        if (left != nullptr && right != nullptr)
        {
            sum = (left == nullptr ? 0 : left->sum) + (right == nullptr ? 0 : right->sum);
        }
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + x;
    }
};
int m, n;
int s_len;
int dis[MaxN];
node *end[MaxN];
node *root[MaxN * 2];
std::vector<int> add[MaxN];
int link(int x)
{
    if (x >= 0)
    {
        return std::lower_bound(dis + 1, dis + 1 + s_len, x) - dis;
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
        return dis[x];
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
        cur->x = last->x + val;
        cur->sum = dis[s] * cur->x;
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
long long query(node *cur, int s, int t, long long k)
{
    if (s == t)
    {
        return dis[s] * k;
    }
    int mid = (s + t) / 2;
    if (k <= cur->left->size)
    {
        return query(cur->left, s, mid, k);
    }
    else
    {
        return cur->left->sum + query(cur->right, mid + 1, t, k - cur->left->size);
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
        dis[i] = z;
    }
    std::sort(dis + 1, dis + 1 + m);
    s_len = std::unique(dis + 1, dis + 1 + m) - dis - 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j < int(add[i].size()); j++)
        {
            add[i][j] = link(add[i][j]);
        }
    }
    root[0] = new node;
    end[0] = root[0];
    build(root[0], 1, s_len);
    int root_cnt = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j < int(add[i].size()); j++)
        {
            int w = add[i][j];
            root_cnt++;
            root[root_cnt] = new node;
            if (w > 0)
            {
                change(root[root_cnt], root[root_cnt - 1], 1, s_len, w, 1);
            }
            else
            {
                change(root[root_cnt], root[root_cnt - 1], 1, s_len, -w, -1);
            }
        }
        end[i] = root[root_cnt];
    }
    long long pre = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        long long a, b, c;
        scanf("%d%lld%lld%lld", &x, &a, &b, &c);
        long long k = 1 + (a * pre + b) % c;
        if (end[x]->size > k)
        {
            pre = query(end[x], 1, s_len, k);
        }
        else
        {
            pre = end[x]->sum;
        }
        printf("%lld\n", pre);
    }
    return 0;
}