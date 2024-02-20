#include <algorithm>
#include <cstdio>
#include <random>
#include <tuple>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int x;
    int key;
    int size;
    int add_lazy;
    bool rev_lazy;
    node *left, *right;
    node(int k)
    {
        x = k;
        key = rnd();
        add_lazy = 0;
        rev_lazy = 0;
        left = nullptr;
        right = nullptr;
    }
    node()
    {
        x = 0;
        key = rnd();
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
    void updateSize()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + 1;
    }
};
std::pair<node *, node *> splitRank(node *cur, int rank)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    int left_son_size = (cur->left == nullptr ? 0 : cur->left->size);
    if (rank <= left_son_size)
    {
        auto temp = splitRank(cur->left, rank);
        cur->left = temp.second;
        cur->updateSize();
        temp.first->updateSize();
        return {temp.first, cur};
    }
    else if (rank == left_son_size + 1)
    {
        node *temp = cur->right;
        cur->right = nullptr;
        cur->updateSize();
        temp->updateSize();
        return {cur, temp};
    }
    else
    {
        auto temp = splitRank(cur->right, rank - left_son_size - 1);
        cur->right = temp.first;
        cur->updateSize();
        temp.second->updateSize();
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
    if (left->key < right->key)
    {
        left->right = merge(left->right, right);
        left->updateSize();
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        right->updateSize();
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
    return 0;
}