#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
class rim
{
  public:
    int to;
    int v, s;
    long long c;
    rim()
    {
        v = 0;
        s = 0;
        c = 0;
        to = 0;
    }
};
class node
{
  public:
    long long x;
    node *left, *right;
    node()
    {
        x = 0;
        left = nullptr;
        right = nullptr;
    }
};
int n;
int cnt;
node *root[MaxN];
std::vector<rim> link[MaxN];
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
void change(node *cur, node *last, int s, int t, int w, long long val)
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
    cur->x = cur->left->x + cur->right->x;
}
inline void change(int x, int y, int w, long long val)
{
    change(root[x], root[y], 1, n, w, val);
}
void dfsInfo(int x, int fa)
{
}
void dfs(int x, int fa)
{
    for (auto next : link[x])
    {
        if (next.to == fa)
        {
            continue;
        }
        change(next.to, x, next.v, next.c);
        dfs(next.to, x);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y, v, c, s;
        scanf("%d%d%d%d%d", &x, &y, &v, &c, &s);
        rim temp;
        temp.to = y;
        temp.v = v;
        temp.s = s;
        temp.c = c;
        link[x].push_back(temp);
        temp.to = x;
        link[y].push_back(temp);
    }
    return 0;
}