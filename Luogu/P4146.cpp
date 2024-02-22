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
        rev_lazy = false;
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
        rev_lazy = false;
        left = nullptr;
        right = nullptr;
    }
    void downstream()
    {
        if (rev_lazy)
        {
            std::swap(left, right);
        }
        if (rev_lazy)
        {
            if (left != nullptr)
            {
                left->rev_lazy ^= 1;
            }
            if (right != nullptr)
            {
                right->rev_lazy ^= 1;
            }
        }
        rev_lazy = false;
        if (left != nullptr)
        {
            left->x += add_lazy;
            left->max += add_lazy;
            left->add_lazy += add_lazy;
        }
        if (right != nullptr)
        {
            right->x += add_lazy;
            right->max += add_lazy;
            right->add_lazy += add_lazy;
        }
        add_lazy = 0;
    }
    void update()
    {
        max = std::max({left == nullptr ? 0 : left->max, right == nullptr ? 0 : right->max, x});
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + 1;
    }
};
std::pair<node *, node *> splitRank(node *cur, int rank)
{
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
void add(int l, int r, int v)
{
    auto temp1 = splitRank(root, l - 1);
    auto temp2 = splitRank(temp1.second, r - l + 1);
    temp2.first->x += v;
    temp2.first->max += v;
    temp2.first->add_lazy += v;
    root = merge(merge(temp1.first, temp2.first), temp2.second);
}
void reversal(int l, int r)
{
    auto temp1 = splitRank(root, l - 1);
    auto temp2 = splitRank(temp1.second, r - l + 1);
    temp2.first->rev_lazy ^= 1;
    root = merge(merge(temp1.first, temp2.first), temp2.second);
}
void query(int l, int r)
{
    auto temp1 = splitRank(root, l - 1);
    auto temp2 = splitRank(temp1.second, r - l + 1);
    printf("%d\n", temp2.first->max);
    root = merge(merge(temp1.first, temp2.first), temp2.second);
}
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
            add(l, r, v);
        }
        else if (op == 2)
        {
            reversal(l, r);
        }
        else if (op == 3)
        {
            query(l, r);
        }
    }
    return 0;
}