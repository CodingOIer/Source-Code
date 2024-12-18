#include <cmath>
#include <cstdio>
#include <random>
#include <tuple>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int x;
    int size;
    int prio;
    node *left, *right;
    node()
    {
        x = 0;
        size = 1;
        prio = rnd();
        left = right = nullptr;
    }
    void update()
    {
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + 1;
    }
};
constexpr int MaxN = 5e5 + 5;
int n;
node *ver[MaxN];
std::tuple<node *, node *> split(node *cur, int x)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    if (x < cur->x)
    {
        node *ck = new node;
        *ck = *cur;
        auto [l, r] = split(cur->left, x);
        ck->left = r;
        ck->update();
        return {l, ck};
    }
    else
    {
        node *ck = new node;
        *ck = *cur;
        auto [l, r] = split(cur->right, x);
        ck->right = l;
        ck->update();
        return {ck, r};
    }
}
std::tuple<node *, node *> splitRank(node *cur, int rk)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    int lestSonSize = cur->left == nullptr ? 0 : cur->left->size;
    if (rk <= lestSonSize)
    {
        node *ck = new node;
        *ck = *cur;
        auto [l, r] = splitRank(cur->left, rk);
        ck->left = r;
        ck->update();
        return {l, ck};
    }
    else
    {
        node *ck = new node;
        *ck = *cur;
        auto [l, r] = splitRank(cur->right, rk - lestSonSize - 1);
        ck->right = l;
        ck->update();
        return {ck, r};
    }
}
node *merge(node *l, node *r)
{
    if (l == nullptr && r == nullptr)
    {
        return nullptr;
    }
    if (l == nullptr)
    {
        return r;
    }
    if (r == nullptr)
    {
        return l;
    }
    if (l->prio < r->prio)
    {
        node *ck = new node;
        *ck = *r;
        auto su = merge(l, r->left);
        ck->left = su;
        ck->update();
        return ck;
    }
    else
    {
        node *ck = new node;
        *ck = *l;
        auto su = merge(l->right, r);
        ck->right = su;
        ck->update();
        return ck;
    }
}
node *insert(int preVer, int x)
{
    node *cur = ver[preVer];
    auto [l, r] = split(cur, x);
    node *cnew = new node;
    cnew->x = x;
    return merge(merge(l, cnew), r);
}
node *remove(int preVer, int x)
{
    node *cur = ver[preVer];
    auto [m, r] = split(cur, x);
    if (m == nullptr)
    {
        return cur;
    }
    auto [l, target] = splitRank(m, m->size - 1);
    if (target->x != x)
    {
        return cur;
    }
    return merge(l, r);
}
int queryValue(int preVer, int x)
{
    node *cur = ver[preVer];
    auto [l, m] = splitRank(cur, x - 1);
    auto [target, r] = splitRank(m, 1);
    return target->x;
}
int queryRank(int preVer, int x)
{
    node *cur = ver[preVer];
    auto [l, r] = split(cur, x - 1);
    return l == nullptr ? 1 : l->size + 1;
}
int queryPre(int preVer, int x)
{
    node *cur = ver[preVer];
    auto [m, r] = split(cur, x - 1);
    if (m == nullptr)
    {
        return -(1ll << 31) + 1;
    }
    auto [l, target] = splitRank(m, m->size - 1);
    if (target == nullptr)
    {
        return -(1ll << 31) + 1;
    }
    return target->x;
}
int queryAft(int preVer, int x)
{
    node *cur = ver[preVer];
    auto [l, m] = split(cur, x);
    if (m == nullptr)
    {
        return (1ll << 31) - 1;
    }
    auto [target, r] = splitRank(m, 1);
    if (target == nullptr)
    {
        return (1ll << 31) - 1;
    }
    return target->x;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        ver[i] = nullptr;
    }
    for (int i = 1; i <= n; i++)
    {
        int op, preVer, x;
        scanf("%d%d%d", &preVer, &op, &x);
        if (op == 1)
        {
            ver[i] = insert(preVer, x);
        }
        else if (op == 2)
        {
            ver[i] = remove(preVer, x);
        }
        else if (op == 3)
        {
            ver[i] = ver[preVer];
            printf("%d\n", queryRank(preVer, x));
        }
        else if (op == 4)
        {
            ver[i] = ver[preVer];
            printf("%d\n", queryValue(preVer, x));
        }
        else if (op == 5)
        {
            ver[i] = ver[preVer];
            printf("%d\n", queryPre(preVer, x));
        }
        else if (op == 6)
        {
            ver[i] = ver[preVer];
            printf("%d\n", queryAft(preVer, x));
        }
    }
    return 0;
}
