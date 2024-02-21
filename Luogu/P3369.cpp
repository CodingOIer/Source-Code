#include <algorithm>
#include <cstdio>
#include <random>
#include <tuple>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int key;
    int prio;
    int size;
    int count;
    node *left, *right;
    node(int val)
    {
        key = val;
        prio = rnd();
        size = 1;
        count = 1;
        left = nullptr;
        right = nullptr;
    }
    void update()
    {
        size = (left != nullptr ? left->size : 0) + (right != nullptr ? right->size : 0) + count;
    }
};
node *root;
std::pair<node *, node *> splitKey(node *cur, int key)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    if (key <= cur->key)
    {
        auto temp = splitKey(cur->left, key);
        cur->left = temp.second;
        cur->update();
        return {temp.first, cur};
    }
    else
    {
        auto temp = splitKey(cur->right, key);
        cur->right = temp.first;
        cur->update();
        return {cur, temp.second};
    }
}
std::tuple<node *, node *, node *> splitRank(node *cur, int rank)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr, nullptr};
    }
    int left_son_size = cur->left != nullptr ? cur->left->size : 0;
    if (rank <= left_son_size)
    {
        node *l, *mid, *r;
        std::tie(l, mid, r) = splitRank(cur->left, rank);
        cur->left = r;
        cur->update();
        return {l, mid, cur};
    }
    else if (rank <= left_son_size + cur->count)
    {
        node *l, *r;
        l = cur->left;
        r = cur->right;
        cur->left = nullptr;
        cur->right = nullptr;
        cur->update();
        return {l, cur, r};
    }
    else
    {
        node *l, *mid, *r;
        std::tie(l, mid, r) = splitRank(cur->right, rank - left_son_size - cur->count);
        cur->right = l;
        cur->update();
        return {cur, mid, r};
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
    if (left->prio > right->prio)
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
void insert(int val)
{
    auto temp1 = splitKey(root, val);
    auto temp2 = splitKey(temp1.first, val - 1);
    if (temp2.second != nullptr)
    {
        temp2.second->count++;
        temp2.second->update();
        root = merge(merge(temp2.first, temp2.second), temp1.second);
    }
    else
    {
        node *temp = new node(val);
        root = merge(merge(temp2.first, temp), temp1.second);
    }
}
void remove(int val)
{
    auto temp1 = splitKey(root, val);
    auto temp2 = splitKey(temp1.first, val - 1);
    temp2.second->count--;
    if (temp2.second->count == 0)
    {
        delete temp2.second;
        root = merge(merge(temp2.first, nullptr), temp1.second);
    }
    else
    {
        root = merge(merge(temp2.first, temp2.second), temp1.second);
    }
}
int queryRank(node *cur, int val)
{
    auto temp = splitKey(cur, val - 1);
    int res = (temp.first != nullptr ? temp.first->size : 0) + 1;
    cur = merge(temp.first, temp.second);
    return res;
}
int queryKey(node *cur, int rank)
{
    node *l, *mid, *r;
    std::tie(l, mid, r) = splitRank(cur, rank);
    int res = mid->key;
    cur = merge(merge(l, mid), r);
    return res;
}
int queryAfterMin(int val)
{
    auto temp = splitKey(root, val);
    int res = queryKey(temp.second, 1);
    root = merge(temp.first, temp.second);
    return res;
}
int queryBeforeMax(int val)
{
    auto temp = splitKey(root, val - 1);
    int res = queryKey(temp.first, temp.first->size);
    root = merge(temp.first, temp.second);
    return res;
}
int n, op, x;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &op, &x);
        switch (op)
        {
        case 1: {
            insert(x);
            break;
        }
        case 2: {
            remove(x);
            break;
        }
        case 3: {
            printf("%d\n", queryRank(root, x));
            break;
        }
        case 4: {
            printf("%d\n", queryKey(root, x));
            break;
        }
        case 5: {
            printf("%d\n", queryBeforeMax(x));
            break;
        }
        case 6: {
            printf("%d\n", queryAfterMin(x));
            break;
        }
        }
    }
    return 0;
}