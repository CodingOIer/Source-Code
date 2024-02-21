#include <algorithm>
#include <cstdio>
#include <random>
#include <tuple>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int x;
    int max;
    int key;
    int size;
    int add_lazy;
    bool rev_lazy;
    node *left, *right;
    node(int k)
    {
        x = k;
        max = k;
        key = rnd();
        size = 1;
        add_lazy = 0;
        rev_lazy = 0;
        left = nullptr;
        right = nullptr;
    }
    node()
    {
        x = 0;
        max = 0;
        key = rnd();
        size = 1;
        add_lazy = 0;
        rev_lazy = 0;
        left = nullptr;
        right = nullptr;
    }
    void downstream()
    {
        if (rev_lazy)
        {
            std::swap(left, right);
        }
        if (left != nullptr)
        {
            left->rev_lazy ^= rev_lazy;
            left->x += add_lazy;
            left->add_lazy += add_lazy;
        }
        if (right != nullptr)
        {
            right->rev_lazy ^= rev_lazy;
            right->x += add_lazy;
            right->add_lazy += add_lazy;
        }
        add_lazy = 0;
        rev_lazy = 0;
    }
    void update()
    {
        max = std::max({left == nullptr ? 0 : left->size, right == nullptr ? 0 : right->size, x});
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + 1;
    }
};
std::pair<node *, node *> splitRank(node *cur, int rank)
{
    if (rank == 0)
    {
        return {nullptr, cur};
    }
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    cur->downstream();
    int left_son_size = (cur->left == nullptr ? 0 : cur->left->size);
    if (rank <= left_son_size)
    {
        auto temp = splitRank(cur->left, rank);
        cur->left = temp.second;
        cur->update();
        temp.first->update();
        return {temp.first, cur};
    }
    else if (rank == left_son_size + 1)
    {
        node *temp = cur->right;
        cur->right = nullptr;
        cur->update();
        return {cur, temp};
    }
    else
    {
        auto temp = splitRank(cur->right, rank - left_son_size - 1);
        cur->right = temp.first;
        cur->update();
        temp.second->update();
        return {cur, temp.second};
    }
}
node *merge(node *left, node *right)
{
    if (left == nullptr && right == nullptr)
    {
        return nullptr;
    }
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
    if (left->key < right->key)
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
node *root;
int main()
{
    scanf("%d%d", &n, &m);
    root = new node(0);
    for (int i = 2; i <= n; i++)
    {
        node *k = new node(0);
        root = merge(root, k);
    }
    for (int i = 1; i <= m; i++)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            int v;
            scanf("%d", &v);
            auto temp1 = splitRank(root, r);
            auto temp2 = splitRank(temp1.first, l - 1);
            temp2.second->x += v;
            temp2.second->max += v;
            temp2.second->add_lazy += v;
            root = merge(merge(temp2.first, temp2.second), temp1.second);
        }
        else if (op == 2)
        {
            auto temp1 = splitRank(root, r);
            auto temp2 = splitRank(temp1.first, l - 1);
            temp2.second->rev_lazy ^= 1;
            root = merge(merge(temp2.first, temp2.second), temp1.second);
        }
        else if (op == 3)
        {
            auto temp1 = splitRank(root, r);
            auto temp2 = splitRank(temp1.first, l - 1);
            printf("%d\n", temp2.second->max);
            root = merge(merge(temp2.first, temp2.second), temp1.second);
        }
    }
    return 0;
}