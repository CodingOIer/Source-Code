#include <cstdio>
#include <cstdlib>
#include <endian.h>
#include <random>
#include <tuple>
#include <utility>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int x;
    int prio;
    int size;
    bool rev;
    long long sum;
    node *left, *right;
    node()
    {
        x = 0;
        sum = 0;
        size = 1;
        rev = false;
        prio = rnd();
    }
    void update()
    {
        sum = (left == nullptr ? 0 : left->sum) + (right == nullptr ? 0 : right->sum) + x;
        size = (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size) + 1;
    }
    void downstream()
    {
        if (rev)
        {
            if (left != nullptr)
            {
                node *ln = new node;
                *ln = *left;
                left = ln;
            }
            if (right != nullptr)
            {
                node *rn = new node;
                *rn = *right;
                right = rn;
            }
            if (left != nullptr)
            {
                left->rev ^= true;
            }
            if (right != nullptr)
            {
                right->rev ^= true;
            }
            std::swap(left, right);
            rev = false;
        }
    }
};
constexpr int MaxN = 2e5 + 5;
int n;
node *ver[MaxN];
std::tuple<node *, node *> splitRank(node *cur, int rk)
{
    if (cur == nullptr)
    {
        return {nullptr, nullptr};
    }
    cur->downstream();
    int leftSonSize = cur->left == nullptr ? 0 : cur->left->size;
    if (rk <= leftSonSize)
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
        auto [l, r] = splitRank(cur->right, rk - leftSonSize - 1);
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
    l->downstream();
    r->downstream();
    if (l->prio < r->prio)
    {
        node *ck = new node;
        *ck = *l;
        auto su = merge(l->right, r);
        ck->right = su;
        ck->update();
        return ck;
    }
    else
    {
        node *ck = new node;
        *ck = *r;
        auto su = merge(l, r->left);
        ck->left = su;
        ck->update();
        return ck;
    }
}
node *insert(int preVer, int after, int x)
{
    node *cur = ver[preVer];
    auto [l, r] = splitRank(cur, after);
    node *cnew = new node;
    cnew->x = x;
    cnew->update();
    return merge(merge(l, cnew), r);
}
node *remove(int preVer, int x)
{
    node *cur = ver[preVer];
    auto [l, m] = splitRank(cur, x - 1);
    auto [target, r] = splitRank(m, 1);
    return merge(l, r);
}
node *reverse(int preVer, int lx, int rx)
{
    node *cur = ver[preVer];
    auto [l, m] = splitRank(cur, lx - 1);
    auto [target, r] = splitRank(m, rx - lx + 1);
    target->rev ^= true;
    return merge(merge(l, target), r);
}
long long query(int preVer, int lx, int rx)
{
    node *cur = ver[preVer];
    auto [l, m] = splitRank(cur, lx - 1);
    auto [target, r] = splitRank(m, rx - lx + 1);
    auto res = target->sum;
    return res;
}
int main()
{
    scanf("%d", &n);
    int lastAnswer = 0;
    for (int i = 1; i <= n; i++)
    {
        int preVer, op;
        scanf("%d%d", &preVer, &op);
        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x ^= lastAnswer;
            y ^= lastAnswer;
            ver[i] = insert(preVer, x, y);
        }
        else if (op == 2)
        {
            int x;
            scanf("%d", &x);
            x ^= lastAnswer;
            ver[i] = remove(preVer, x);
        }
        else if (op == 3)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l ^= lastAnswer;
            r ^= lastAnswer;
            ver[i] = reverse(preVer, l, r);
        }
        else if (op == 4)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l ^= lastAnswer;
            r ^= lastAnswer;
            ver[i] = ver[preVer];
            long long answer = query(preVer, l, r);
            lastAnswer = answer;
            printf("%lld\n", answer);
        }
    }
    return 0;
}
