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
    node *left = nullptr, *right = nullptr;
    node(int value)
    {
        left = nullptr;
        right = nullptr;
        key = value;
        size = 1;
        count = 1;
        prio = rnd() >> 1;
    }
    void update_size()
    {
        size = count;
        if (left != nullptr)
        {
            size += left->size;
        }
        if (right != nullptr)
        {
            size += right->size;
        }
    }
};
node *root;
std::pair<node *, node *> split(node *root, int key)
{
    if (root == nullptr)
    {
        return {nullptr, nullptr};
    }
    else if (key >= root->key)
    {
        auto tmp = split(root->right, key);
        root->right = tmp.first;
        root->update_size();
        return {root, tmp.second};
    }
    else if (key <= root->key)
    {
        auto temp = split(root->left, key);
        root->left = temp.second;
        root->update_size();
        return {temp.first, root};
    }
}
std::tuple<node *, node *, node *> splitRank(node *root, int rank)
{
    if (root == nullptr)
    {
        return {nullptr, nullptr, nullptr};
    }
    int left_son_size = root->left != nullptr ? root->left->size : 0;
    if (rank <= left_son_size)
    {
        node *l, *mid, *r;
        std::tie(l, mid, r) = splitRank(root->left, rank);
        root->left = r;
        root->update_size();
        return {l, mid, root};
    }
    else if (rank <= left_son_size + root->count)
    {
        node *l, *r;
        l = root->left;
        r = root->right;
        root->left = nullptr;
        root->right = nullptr;
        root->update_size();
        return {l, root, r};
    }
    else
    {
        node *l, *mid, *r;
        std::tie(l, mid, r) = splitRank(root->right, rank - left_son_size - root->count);
        root->right = l;
        root->update_size();
        return {root, mid, r};
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
    if (left->prio < right->prio)
    {
        left->right = merge(left->right, right);
        left->update_size();
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        right->update_size();
        return right;
    }
}
void insert(int key)
{
    auto temp1 = split(root, key);
    auto temp2 = split(temp1.first, key - 1);
    node *temp;
    if (temp2.second == nullptr)
    {
        temp = new node(key);
    }
    else
    {
        temp2.second->count++;
        temp2.second->update_size();
    }
    node *temp3 = merge(temp2.first, temp2.second != nullptr ? temp2.second : temp);
    root = merge(temp3, temp1.second);
}
void del(int key)
{
    auto temp1 = split(root, key);
    auto temp2 = split(temp1.first, key - 1);
    if (temp2.second->count > 1)
    {
        temp2.second->count--;
        temp2.second->update_size();
        temp2.first = merge(temp2.first, temp2.second);
    }
    else
    {
        if (temp1.first == temp2.second)
        {
            temp1.first = nullptr;
        }
        delete temp2.second;
        temp2.second = nullptr;
    }
    root = merge(temp2.first, temp1.second);
}
int query_rank(node *root, int key)
{
    auto temp = split(root, key - 1);
    int res = (temp.first != nullptr ? temp.first->size : 0) + 1;
    root = merge(temp.first, temp.second);
    return res;
}
int query_value(node *root, int rank)
{
    node *l, *mid, *r;
    std::tie(l, mid, r) = splitRank(root, rank);
    int res = mid->key;
    root = merge(merge(l, mid), r);
    return res;
}
int pre_max(int key)
{
    auto temp = split(root, key - 1);
    int res = query_value(temp.first, temp.first->size);
    root = merge(temp.first, temp.second);
    return res;
}
int lat_min(int key)
{
    auto temp = split(root, key);
    int res = query_value(temp.second, 1);
    root = merge(temp.first, temp.second);
    return res;
}
int answer;
int n, m, op, x, last;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        insert(x);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &op, &x);
        x ^= last;
        switch (op)
        {
        case 1: {
            insert(x);
            break;
        }
        case 2: {
            del(x);
            break;
        }
        case 3: {
            int res = query_rank(root, x);
            last = res;
            answer ^= res;
            break;
        }
        case 4: {
            int res = query_value(root, x);
            last = res;
            answer ^= res;
            break;
        }
        case 5: {
            int res = pre_max(x);
            last = res;
            answer ^= res;
            break;
        }
        case 6: {
            int res = lat_min(x);
            last = res;
            answer ^= res;
            break;
        }
        }
    }
    printf("%d\n", answer);
    return 0;
}