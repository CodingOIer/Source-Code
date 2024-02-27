#include <algorithm>
#include <cstdio>
#include <random>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 3e5 + 5;
class node
{
  public:
    long long l, r;
    int key;
    int size;
    node *left, *right;
    node()
    {
        l = 0;
        r = 0;
        key = rnd();
        size = 0;
        left = nullptr;
        right = nullptr;
    }
    node(long long x)
    {
        l = x;
        r = x;
        key = rnd();
        size = 1;
        left = nullptr;
        right = nullptr;
    }
    void update()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + r - l + 1;
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
std::pair<node *, node *> make(node *cur, int x)
{
    node *l, *r;
    l = new node;
    r = new node;
    l->l = cur->l;
    l->r = cur->l + x - 1;
    r->l = cur->l + x;
    r->r = cur->r;
    l->update();
    r->update();
    delete cur;
    if (r->l > r->r)
    {
        delete r;
        r = nullptr;
    }
    return {l, r};
}
std::pair<node *, node *> split(node *cur, int x)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    int left_son_size = (cur->left == nullptr ? 0 : cur->left->size);
    if (x <= left_son_size)
    {
        auto temp = split(cur->left, x);
        cur->left = temp.second;
        cur->update();
        return {temp.first, cur};
    }
    else if (x <= left_son_size + cur->r - cur->l + 1)
    {
        node *l, *r;
        l = cur->left;
        r = cur->right;
        cur->left = nullptr;
        cur->right = nullptr;
        auto temp = make(cur, x - left_son_size);
        return {merge(l, temp.first), merge(temp.second, r)};
    }
    else
    {
        auto temp = split(cur->right, x - (left_son_size + cur->r - cur->l + 1));
        cur->right = temp.first;
        cur->update();
        return {cur, temp.second};
    }
}
int n, m, q;
node *line[MaxN];
node *last_row;
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (long long i = 1; i <= n; i++)
    {
        line[i] = new node;
        line[i]->l = (i - 1) * m + 1;
        line[i]->r = i * m - 1;
        line[i]->update();
    }
    for (long long i = 1; i <= n; i++)
    {
        last_row = merge(last_row, new node(i * m));
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y == m)
        {
            auto temp1 = split(last_row, x);
            auto temp2 = split(temp1.first, x - 1);
            printf("%lld\n", temp2.second->l);
            last_row = merge(merge(temp2.first, temp1.second), temp2.second);
        }
        else
        {
            auto line_temp1 = split(line[x], y);
            auto line_temp2 = split(line_temp1.first, y - 1);
            auto row_temp1 = split(last_row, x);
            auto row_temp2 = split(row_temp1.first, x - 1);
            printf("%lld\n", line_temp2.second->l);
            line[x] = merge(merge(line_temp2.first, line_temp1.second), row_temp2.second);
            last_row = merge(merge(row_temp2.first, row_temp1.second), line_temp2.second);
        }
    }
    return 0;
}