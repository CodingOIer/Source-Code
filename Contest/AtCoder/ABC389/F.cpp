#include <cstdio>
#include <random>
#include <tuple>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 3e5 + 5;
class node
{
  public:
    int x;
    int lazy;
    int prio;
    node *left, *right;
    node()
    {
        x = 0;
        lazy = 0;
        prio = rnd();
        left = right = nullptr;
    }
    void downstream()
    {
        if (lazy != 0)
        {
            if (left != nullptr)
            {
                left->x += lazy;
                left->lazy += lazy;
            }
            if (right != nullptr)
            {
                right->x += lazy;
                right->lazy += lazy;
            }
            lazy = 0;
        }
    }
};
int n, q;
int cl[MaxN];
int cr[MaxN];
node *root;
node *where[MaxN];
std::tuple<node *, node *> split(node *c, int x)
{
    if (c == nullptr)
    {
        return {nullptr, nullptr};
    }
    c->downstream();
    if (x < c->x)
    {
        auto [l, r] = split(c->left, x);
        c->left = r;
        return {l, c};
    }
    else
    {
        auto [l, r] = split(c->right, x);
        c->right = l;
        return {c, r};
    }
}
node *merge(node *l, node *r)
{
    if (l == nullptr && r == nullptr)
    {
        return nullptr;
    }
    if (l == nullptr)
    {
        return r;
    }
    if (r == nullptr)
    {
        return l;
    }
    l->downstream();
    r->downstream();
    if (l->prio < r->prio)
    {
        l->right = merge(l->right, r);
        return l;
    }
    else
    {
        r->left = merge(l, r->left);
        return r;
    }
}
void downstreamAllTag(node *c)
{
    if (c == nullptr)
    {
        return;
    }
    c->downstream();
    downstreamAllTag(c->left);
    downstreamAllTag(c->right);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &cl[i], &cr[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int x;
        scanf("%d", &x);
        auto [l, t] = split(root, x - 1);
        auto [m, r] = split(t, x);
        if (m == nullptr)
        {
            m = new node;
            m->x = x;
        }
        where[i] = m;
        root = merge(merge(l, m), r);
    }
    for (int i = 1; i <= n; i++)
    {
        auto [l, t] = split(root, cl[i] - 1);
        auto [m, r] = split(t, cr[i]);
        if (m != nullptr)
        {
            m->x++;
            m->lazy++;
        }
        root = merge(merge(l, m), r);
    }
    downstreamAllTag(root);
    for (int i = 1; i <= q; i++)
    {
        printf("%d\n", where[i]->x);
    }
    return 0;
}
