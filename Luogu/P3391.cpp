#include <cstdio>
#include <random>
#include <utility>
constexpr int MaxN = 1e5 + 5;
std::mt19937 rnd(6);
class node
{
  public:
    int x;
    int prio;
    int size;
    bool revTag;
    node *left, *right;
    node()
    {
        x = 0;
        size = 1;
        prio = rnd();
        revTag = false;
        left = nullptr;
        right = nullptr;
    }
    node(int a)
    {
        x = a;
        size = 1;
        prio = rnd();
        revTag = false;
        left = nullptr;
        right = nullptr;
    }
    void downstream()
    {
        if (revTag)
        {
            std::swap(left, right);
            if (left != nullptr)
            {
                left->revTag ^= true;
            }
            if (right != nullptr)
            {
                right->revTag ^= true;
            }
            revTag = false;
        }
    }
    void update()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + 1;
    }
};
int n, m;
node *root;
void insert(node *c, node *x)
{
    if (c == root && c->prio > x->prio)
    {
        x->left = c;
        x->update();
        root = x;
        return;
    }
    if (c->right == nullptr)
    {
        c->right = x;
        c->update();
        return;
    }
    if (c->right->prio > x->prio)
    {
        x->left = c->right;
        x->update();
        c->right = x;
        c->update();
        return;
    }
    insert(c->right, x);
    c->update();
}
std::pair<node *, node *> split(node *c, int rk)
{
    if (c == nullptr)
    {
        return {nullptr, nullptr};
    }
    c->downstream();
    int leftSonSize = (c->left == nullptr ? 0 : c->left->size);
    if (rk <= leftSonSize)
    {
        auto temp = split(c->left, rk);
        c->left = temp.second;
        c->update();
        return {temp.first, c};
    }
    else if (rk <= leftSonSize + 1)
    {
        auto r = c->right;
        c->right = nullptr;
        c->update();
        return {c, r};
    }
    else
    {
        auto temp = split(c->right, rk - leftSonSize - 1);
        c->right = temp.first;
        c->update();
        return {c, temp.second};
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
        l->update();
        return l;
    }
    else
    {
        r->left = merge(l, r->left);
        r->update();
        return r;
    }
}
void pt(node *c, bool f = true)
{
    if (c == nullptr)
    {
        return;
    }
    c->downstream();
    pt(c->left, false);
    printf("%d ", c->x);
    pt(c->right, false);
    if (f)
    {
        printf("\n");
    }
}
void rev(int l, int r)
{
    auto temp1 = split(root, r);
    auto temp2 = split(temp1.first, l - 1);
    temp2.second->revTag ^= true;
    auto k = merge(temp2.first, temp2.second);
    root = merge(k, temp1.second);
}
int main()
{
    scanf("%d%d", &n, &m);
    root = new node(1);
    for (int i = 2; i <= n; i++)
    {
        insert(root, new node(i));
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        rev(l, r);
    }
    pt(root);
    return 0;
}