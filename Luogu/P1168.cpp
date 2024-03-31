#include <algorithm>
#include <cstdio>
#include <random>
#include <tuple>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int x;
    int cnt;
    int prio;
    int size;
    node *left, *right;
    node()
    {
        x = 0;
        cnt = 0;
        size = 0;
        prio = rnd();
        left = nullptr;
        right = nullptr;
    }
    void update()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + cnt;
    }
};
int n;
std::pair<node *, node *> split(node *c, int v)
{
    if (c == nullptr)
    {
        return {nullptr, nullptr};
    }
    if (v == c->x)
    {
        auto temp = c->right;
        c->right = nullptr;
        c->update();
        return {c, temp};
    }
    else if (v < c->x)
    {
        auto temp = split(c->left, v);
        c->left = temp.second;
        c->update();
        return {temp.first, c};
    }
    else if (v > c->x)
    {
        auto temp = split(c->right, v);
        c->right = temp.first;
        c->update();
        return {c, temp.second};
    }
}
std::tuple<node *, node *, node *> splitRank(node *c, int rk)
{
    if (c == nullptr)
    {
        return {nullptr, nullptr, nullptr};
    }
    int left_son_size = c->left == nullptr ? 0 : c->left->size;
    if (rk <= left_son_size)
    {
        node *l, *m, *r;
        std::tie(l, m, r) = splitRank(c->left, rk);
        c->left = r;
        c->update();
        return {l, m, c};
    }
    else if (rk <= left_son_size + c->cnt)
    {
        auto l = c->left;
        auto r = c->right;
        c->left = nullptr;
        c->right = nullptr;
        c->update();
        return {l, c, r};
    }
    else
    {
        node *l, *m, *r;
        std::tie(l, m, r) = splitRank(c->right, rk - left_son_size - c->cnt);
        c->right = l;
        c->update();
        return {c, m, r};
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
void insert(int val)
{
    auto temp1 = split(root, val);
    auto temp2 = split(temp1.first, val - 1);
    if (temp2.second == nullptr)
    {
        temp2.second = new node;
        temp2.second->x = val;
    }
    temp2.second->cnt++;
    temp2.second->update();
    root = merge(merge(temp2.first, temp2.second), temp1.second);
}
int find(int w)
{
    node *l, *m, *r;
    std::tie(l, m, r) = splitRank(root, w);
    int res = m->x;
    merge(merge(l, m), r);
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        insert(x);
        if (i % 2 == 0)
        {
            continue;
        }
        printf("%d\n", find(i / 2 + 1));
    }
    return 0;
}