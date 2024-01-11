#include <algorithm>
#include <cstdio>
#include <random>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 5e4 + 5;
int p[MaxN];
class node
{
  public:
    int val;
    int key;
    int max;
    int prio;
    int size;
    int lazy_add;
    bool lazy_upturn;
    node *left, *right;
    node(int x)
    {
        val = 0;
        key = x;
        max = 0;
        prio = rnd();
        size = 1;
        lazy_add = 0;
        lazy_upturn = false;
        left = nullptr;
        right = nullptr;
    }
    void downstream()
    {
        if (lazy_upturn)
        {
            std::swap(left, right);
        }
        if (left != nullptr)
        {
            left->val += lazy_add;
            left->max += lazy_add;
            left->lazy_add += lazy_add;
            left->lazy_upturn ^= lazy_upturn;
        }
        if (right != nullptr)
        {
            right->val += lazy_add;
            right->max += lazy_add;
            right->lazy_add += lazy_add;
            right->lazy_upturn ^= lazy_upturn;
        }
        lazy_add = 0;
        lazy_upturn = false;
    }
    void update()
    {
        downstream();
        max = std::max({(left != nullptr ? left->max : 0), (right != nullptr ? right->max : 0), val});
        size = (left != nullptr ? left->size : 0) + (right != nullptr ? right->size : 0) + 1;
    }
};
node *root;
node *dfsBuild(node *cur, node *x, node *fa)
{
    if (cur == nullptr)
    {
        fa->right = x;
        x->update();
        cur = x;
    }
    else if (cur->prio > x->prio)
    {
        if (fa != nullptr)
        {
            fa->right = x;
        }
        x->left = cur;
        x->update();
        cur = x;
    }
    else
    {
        dfsBuild(cur->right, x, cur);
        cur->update();
    }
    return cur;
}
void build(int n)
{
    root = new node(1);
    for (int i = 2; i <= n; i++)
    {
        node *temp = new node(i);
        root = dfsBuild(root, temp, nullptr);
    }
}
void output(node *cur)
{
    if (cur == nullptr)
    {
        return;
    }
    output(cur->left);
    printf("%d ", cur->key);
    output(cur->right);
}
std::pair<node *, node *> splitRank(node *cur, int rank)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    cur->downstream();
    int left_son_size = cur->left != nullptr ? cur->left->size : 0;
    if (rank <= left_son_size)
    {
        node *l, *r;
        auto temp = splitRank(cur->left, rank);
        l = temp.first;
        r = temp.second;
        cur->left = r;
        cur->update();
        return {l, cur};
    }
    else if (rank == left_son_size + 1)
    {
        node *r = cur->right;
        cur->right = nullptr;
        cur->update();
        return {cur, r};
    }
    else
    {
        node *l, *r;
        auto temp = splitRank(cur->right, rank - left_son_size - 1);
        l = temp.first;
        r = temp.second;
        cur->right = l;
        cur->update();
        return {cur, r};
    }
}
node *merge(node *left, node *right)
{
    if (left == nullptr && right == nullptr)
    {
        return nullptr;
    }
    else if (left == nullptr)
    {
        return right;
    }
    else if (right == nullptr)
    {
        return left;
    }
    left->downstream();
    right->downstream();
    if (left->prio < right->prio)
    {
        left->right = merge(left->right, right);
        left->update();
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        right->update();
        return right;
    }
}
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    build(n);
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1: {
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            auto temp1 = splitRank(root, y);
            auto temp2 = splitRank(temp1.first, x - 1);
            temp2.second->val += v;
            temp2.second->max += v;
            temp2.second->lazy_add += v;
            root = merge(merge(temp2.first, temp2.second), temp1.second);
            break;
        }
        case 2: {
            int x, y;
            scanf("%d%d", &x, &y);
            auto temp1 = splitRank(root, y);
            auto temp2 = splitRank(temp1.first, x - 1);
            temp2.second->lazy_upturn ^= 1;
            root = merge(merge(temp2.first, temp2.second), temp1.second);
            break;
        }
        case 3: {
            int x, y;
            scanf("%d%d", &x, &y);
            auto temp1 = splitRank(root, y);
            auto temp2 = splitRank(temp1.first, x - 1);
            printf("%d\n", temp2.second->max);
            root = merge(merge(temp2.first, temp2.second), temp1.second);
            break;
        }
        }
    }
    return 0;
}