#include <algorithm>
#include <cstdio>
#include <random>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int max;
    int key;
    int size;
    int value;
    int add_lazy;
    bool rev_lazy;
    node *left, *right;
    node()
    {
        max = 0;
        key = rnd();
        size = 1;
        value = 0;
        add_lazy = 0;
        rev_lazy = false;
        left = nullptr;
        right = nullptr;
    }
    void downstream()
    {
        if (rev_lazy)
        {
            std::swap(left, right);
            if (left != nullptr)
            {
                left->rev_lazy ^= 1;
            }
            if (right != nullptr)
            {
                right->rev_lazy ^= 1;
            }
            rev_lazy = false;
        }
        if (add_lazy != 0)
        {
            if (left != nullptr)
            {
                left->max += add_lazy;
                left->value += add_lazy;
                left->add_lazy += add_lazy;
            }
            if (right != nullptr)
            {
                right->max += add_lazy;
                right->value += add_lazy;
                right->add_lazy += add_lazy;
            }
            add_lazy = 0;
        }
    }
    void update()
    {
        max = std::max({left == nullptr ? -0x3f3f3f3f : left->max, right == nullptr ? -0x3f3f3f3f : right->max, value});
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + 1;
    }
};
node *merge(node *left, node *right)
{
    if (left == nullptr && right == nullptr)
    {
        return nullptr;
    }
    if (left == nullptr)
    {
        right->downstream();
        return right;
    }
    if (right == nullptr)
    {
        left->downstream();
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
std::pair<node *, node *> split(node *cur, int rank)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    cur->downstream();
    int left_son_size = (cur->left == nullptr ? 0 : cur->left->size);
    if (rank <= left_son_size)
    {
        auto temp = split(cur->left, rank);
        cur->left = temp.second;
        cur->update();
        return {temp.first, cur};
    }
    else if (rank == left_son_size + 1)
    {
        auto temp = cur->right;
        cur->right = nullptr;
        cur->update();
        return {cur, temp};
    }
    else
    {
        auto temp = split(cur->right, rank - left_son_size - 1);
        cur->right = temp.first;
        cur->update();
        return {cur, temp.second};
    }
}
int n, m;
node *root;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        root = merge(root, new node);
    }
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            auto temp1 = split(root, r);
            auto temp2 = split(temp1.first, l - 1);
            temp2.second->max += k;
            temp2.second->value += k;
            temp2.second->add_lazy += k;
            root = merge(merge(temp2.first, temp2.second), temp1.second);
        }
        else if (op == 2)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            auto temp1 = split(root, r);
            auto temp2 = split(temp1.first, l - 1);
            temp2.second->rev_lazy ^= 1;
            root = merge(merge(temp2.first, temp2.second), temp1.second);
        }
        else if (op == 3)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            auto temp1 = split(root, r);
            auto temp2 = split(temp1.first, l - 1);
            printf("%d\n", temp2.second->max);
            root = merge(merge(temp2.first, temp2.second), temp1.second);
        }
    }
    return 0;
}