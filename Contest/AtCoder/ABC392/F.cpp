#include <cstdio>
#include <random>
#include <tuple>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int x;
    int size;
    int prio;
    node *left, *right;
    node()
    {
        x = 0;
        size = 1;
        prio = rnd();
        left = right = nullptr;
    }
    inline void update()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + 1;
    }
};
int n;
node *root;
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
std::tuple<node *, node *> split(node *cur, int cut)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    if (cut < cur->x)
    {
        auto k = split(cur->left, cut);
        cur->left = std::get<1>(k);
        cur->update();
        return {std::get<0>(k), cur};
    }
    else
    {
        auto k = split(cur->right, cut);
        cur->right = std::get<0>(k);
        cur->update();
        return {cur, std::get<1>(k)};
    }
}
std::tuple<node *, node *> splitRank(node *cur, int rank)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    int leftSonSize = cur->left == nullptr ? 0 : cur->left->size;
    if (rank <= leftSonSize)
    {
        auto k = splitRank(cur->left, rank);
        cur->left = std::get<1>(k);
        cur->update();
        return {std::get<0>(k), cur};
    }
    else
    {
        auto k = splitRank(cur->right, rank - leftSonSize - 1);
        cur->right = std::get<0>(k);
        cur->update();
        return {cur, std::get<1>(k)};
    }
}
void insert(int x)
{
    node *ptr = new node;
    ptr->x = x;
    auto k = split(root, x);
    root = merge(merge(std::get<0>(k), ptr), std::get<1>(k));
}
void remove(int x)
{
    auto k1 = split(root, x - 1);
    auto k2 = splitRank(std::get<1>(k1), 1);
    delete std::get<0>(k2);
    root = merge(std::get<0>(k1), std::get<1>(k2));
}
int queryRank(int x)
{
    auto k = split(root, x - 1);
    int res = std::get<0>(k) == nullptr ? 0 : std::get<0>(k)->size;
    root = merge(std::get<0>(k), std::get<1>(k));
    return res + 1;
}
int query(int x)
{
    auto k1 = splitRank(root, x);
    auto k2 = splitRank(std::get<0>(k1), x - 1);
    int res = std::get<1>(k2)->x;
    root = merge(merge(std::get<0>(k2), std::get<1>(k2)), std::get<1>(k1));
    return res;
}
int queryPre(int x)
{
    auto k1 = split(root, x - 1);
    auto k2 = splitRank(std::get<0>(k1), std::get<0>(k1)->size - 1);
    int res = std::get<1>(k2)->x;
    root = merge(merge(std::get<0>(k2), std::get<1>(k2)), std::get<1>(k1));
    return res;
}
int queryAft(int x)
{
    auto k1 = split(root, x);
    auto k2 = splitRank(std::get<1>(k1), 1);
    int res = std::get<0>(k2)->x;
    root = merge(std::get<0>(k1), merge(std::get<0>(k2), std::get<1>(k2)));
    return res;
}
void out(node *cur)
{
    if (cur == nullptr)
    {
        return;
    }
    out(cur->left);
    printf("%d ", cur->x);
    out(cur->right);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u;
        scanf("%d", &u);
        auto [l, r] = splitRank(root, u - 1);
        auto cur = new node;
        cur->x = i;
        root = merge(merge(l, cur), r);
    }
    out(root);
    printf("\n");
    return 0;
}
