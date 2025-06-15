#include <cstdio>
#include <random>
#include <tuple>
#include <vector>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int x;
    int prio;
    int size;
    bool rev;
    node *left;
    node *right;
    node()
    {
        x = 0;
        prio = rnd();
        size = 1;
        rev = false;
        left = nullptr;
        right = nullptr;
    }
    void upstream()
    {
        size = 1 + (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size);
    }
    void downstream()
    {
        if (rev)
        {
            std::swap(left, right);
            if (left != nullptr)
            {
                left->rev ^= true;
            }
            if (right != nullptr)
            {
                right->rev ^= true;
            }
            rev = false;
        }
    }
};
int n, m;
node *root;
node *merge(node *left, node *right)
{
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }
    left->downstream();
    right->downstream();
    if (left->prio < right->prio)
    {
        left->right = merge(left->right, right);
        left->upstream();
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        right->upstream();
        return right;
    }
}
std::tuple<node *, node *> splitRank(node *c, int rk)
{
    if (c == nullptr)
    {
        return {nullptr, nullptr};
    }
    c->downstream();
    int leftSize = 1 + (c->left == nullptr ? 0 : c->left->size);
    if (leftSize <= rk)
    {
        auto [l, r] = splitRank(c->right, rk - leftSize);
        c->right = l;
        c->upstream();
        return {c, r};
    }
    else
    {
        auto [l, r] = splitRank(c->left, rk);
        c->left = r;
        c->upstream();
        return {l, c};
    }
}
void output(node *c, std::vector<int> &v)
{
    c->downstream();
    if (c->left != nullptr)
    {
        output(c->left, v);
    }
    v.push_back(c->x);
    if (c->right != nullptr)
    {
        output(c->right, v);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        node *c = new node;
        c->x = i;
        root = merge(root, c);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        auto [l, t] = splitRank(root, x - 1);
        auto [m, r] = splitRank(t, y - x + 1);
        m->rev ^= true;
        root = merge(merge(l, m), r);
    }
    std::vector<int> answer;
    output(root, answer);
    for (const auto &val : answer)
    {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}