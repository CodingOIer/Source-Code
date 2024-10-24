#include <cstdio>
#include <random>
#include <utility>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int x;
    int size;
    int prio;
    node *left, *right;
    node(int a)
    {
        x = a;
        size = 1;
        prio = rnd();
        left = nullptr;
        right = nullptr;
    }
    void update()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + 1;
    }
};
int add;
int left;
int n, min;
node *root;
std::pair<node *, node *> split(node *c, int x)
{
    if (c == nullptr)
    {
        return {nullptr, nullptr};
    }
    if (x <= c->x)
    {
        auto temp = split(c->left, x);
        c->left = temp.second;
        c->update();
        return {temp.first, c};
    }
    else
    {
        auto temp = split(c->right, x);
        c->right = temp.first;
        c->update();
        return {c, temp.second};
    }
}
std::pair<node *, node *> split_rank(node *c, int rk)
{
    if (c == nullptr)
    {
        return {nullptr, nullptr};
    }
    int left_son_size = (c->left == nullptr ? 0 : c->size);
    if (rk <= left_son_size)
    {
        auto temp = split_rank(c->left, rk);
        c->left = temp.second;
        c->update();
        return {temp.first, c};
    }
    else if (rk == left_son_size + 1)
    {
        node *r = c->right;
        c->update();
        return {c, r};
    }
    else
    {
        auto temp = split_rank(c->right, rk - left_son_size - 1);
        c->right = temp.first;
        c->update();
        return {c, temp.second};
    }
}
node *merge(node *l, node *r)
{
    if (l == nullptr && r == nullptr)
    {
        return nullptr;
    }
    else if (l == nullptr)
    {
        return r;
    }
    else if (r == nullptr)
    {
        return l;
    }
    if (l->prio < r->prio)
    {
        l->right = merge(l->right, r);
        l->update();
        return l;
    }
    else
    {
        r->left = merge(l, r->left);
        r->update();
        return r;
    }
}
void clear()
{
    auto temp = split(root, min - 1);
    left += (temp.first == nullptr ? 0 : temp.first->size);
    root = temp.second;
}
void insert(int x)
{
    auto temp1 = split(root, x);
    auto temp2 = split(temp1.first, x - 1);
    root = merge(merge(temp2.first, merge(temp2.second, new node(x))), temp1.second);
}
int find(int x)
{
    auto temp1 = split_rank(root, x);
    auto temp2 = split_rank(temp1.first, x - 1);
    int r = temp2.second->x;
    merge(merge(temp2.first, temp2.second), temp1.second);
    return r;
}
int main()
{
    scanf("%d%d", &n, &min);
    for (int i = 1; i <= n; i++)
    {
        char op = '\0';
        int x;
        for (; !(op == 'I' || op == 'A' || op == 'S' || op == 'F');)
        {
            op = getchar();
        }
        scanf("%d", &x);
        if (op == 'I')
        {
            if (x + add < min)
            {
                continue;
            }
            insert(x + add);
        }
        else if (op == 'A')
        {
            min -= x;
            add -= x;
        }
        else if (op == 'S')
        {
            min += x;
            add += x;
            clear();
        }
        else if (op == 'F')
        {
            if (root == nullptr || root->size - x + 1 <= 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", find(root->size - x + 1) - add);
            }
        }
    }
    printf("%d\n", left);
    return 0;
}