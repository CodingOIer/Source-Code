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
    int cnt;
    int size;
    node *left, *right;
    node(int k)
    {
        x = k;
        key = rnd();
        cnt = 1;
        size = 1;
        left = nullptr;
        right = nullptr;
    }
    void update()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + cnt;
    }
};
std::pair<node *, node *> splitValue(node *cur, int val)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    if (val < cur->x)
    {
        auto temp = splitValue(cur->left, val);
        cur->left = temp.second;
        cur->update();
        return {temp.first, cur};
    }
    else
    {
        auto temp = splitValue(cur->right, val);
        cur->right = temp.first;
        cur->update();
        return {cur, temp.second};
    }
}
std::tuple<node *, node *, node *> splitRank(node *cur, int rk)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr, nullptr};
    }
    int left_son_size = (cur->left == nullptr ? 0 : cur->left->size);
    if (rk <= left_son_size)
    {
        node *l, *m, *r;
        std::tie(l, m, r) = splitRank(cur->left, rk);
        cur->left = r;
        cur->update();
        return {l, m, cur};
    }
    else if (rk <= left_son_size + cur->cnt)
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
        node *l, *m, *r;
        std::tie(l, m, r) = splitRank(cur->right, rk - left_son_size - cur->cnt);
        cur->right = l;
        cur->update();
        return {cur, m, r};
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
node *root;
void insert(int x)
{
    auto temp1 = splitValue(root, x);
    auto temp2 = splitValue(temp1.first, x - 1);
    if (temp2.second == nullptr)
    {
        temp2.second = new node(x);
    }
    else
    {
        temp2.second->cnt++;
        temp2.second->update();
    }
    root = merge(merge(temp2.first, temp2.second), temp1.second);
}
void remove(int x)
{
    auto temp1 = splitValue(root, x);
    auto temp2 = splitValue(temp1.first, x - 1);
    if (temp2.second->cnt > 1)
    {
        temp2.second->cnt--;
        temp2.second->update();
    }
    else
    {
        if (temp2.second != nullptr)
        {
            delete temp2.second;
        }
        temp2.second = nullptr;
    }
    root = merge(merge(temp2.first, temp2.second), temp1.second);
}
int queryRank(int x)
{
    auto temp = splitValue(root, x - 1);
    int res = (temp.first == nullptr ? 0 : temp.first->size) + 1;
    root = merge(temp.first, temp.second);
    return res;
}
int queryValue(node *root, int x)
{
    node *l, *m, *r;
    std::tie(l, m, r) = splitRank(root, x);
    int res = m->x;
    root = merge(merge(l, m), r);
    return res;
}
int queryBeforeMax(int x)
{
    auto temp = splitValue(root, x - 1);
    int res = queryValue(temp.first, temp.first->size);
    root = merge(temp.first, temp.second);
    return res;
}
int queryAfterMin(int x)
{
    auto temp = splitValue(root, x);
    int res = queryValue(temp.second, 1);
    root = merge(temp.first, temp.second);
    return res;
}
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int op, x;
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
            printf("%d\n", queryRank(x));
            break;
        }
        case 4: {
            printf("%d\n", queryValue(root, x));
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