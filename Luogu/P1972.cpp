#include <cstdio>
constexpr int MaxN = 1e6 + 5;
class node
{
  public:
    int x;
    int k;
    node *left;
    node *right;
    node()
    {
        x = 0;
        k = 0;
        left = nullptr;
        right = nullptr;
    }
    void update()
    {
        k = (left == nullptr ? 0 : left->k) + (right == nullptr ? 0 : right->k) + x;
    }
};
int n, m;
int p[MaxN];
node *root;
void build(node *c, int s, int t)
{
    if (s == t)
    {
        return;
    }
    int mid = (s + t) / 2;
    c->left = new node;
    c->right = new node;
    build(c->left, s, mid);
    build(c->right, mid + 1, t);
}
void change(node *c, int s, int t, int w, int v)
{
    if (s == t)
    {
        c->x++;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    root = new node;
    build(root, 1, n);
    return 0;
}