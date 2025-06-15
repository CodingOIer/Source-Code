#include <cstdio>
#include <random>
#include <tuple>
#include <vector>
std::mt19937 rnd(std::random_device{}());
class node
{
  public:
    int prio;
    int size;
    char x;
    bool rev;
    node *left;
    node *right;
    node()
    {
        x = '\0';
        prio = rnd();
        size = 1;
        rev = false;
        left = nullptr;
        right = nullptr;
    }
    void upstream()
    {
        size = 1 + (left == nullptr ? 0 : left->size) + (right == nullptr ? 0 : right->size);
    }
    void downstream()
    {
        if (rev)
        {
            std::swap(left, right);
            if (left != nullptr)
            {
                left->rev ^= true;
            }
            if (right != nullptr)
            {
                right->rev ^= true;
            }
            rev = false;
        }
    }
};
constexpr int MaxN = 5e5 + 5;
int n, m;
char s[MaxN];
node *root;
node *merge(node *left, node *right)
{
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
    if (left->prio < right->prio)
    {
        left->right = merge(left->right, right);
        left->upstream();
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        right->upstream();
        return right;
    }
}
std::tuple<node *, node *> splitRank(node *c, int rk)
{
    if (c == nullptr)
    {
        return {nullptr, nullptr};
    }
    c->downstream();
    int leftSize = 1 + (c->left == nullptr ? 0 : c->left->size);
    if (leftSize <= rk)
    {
        auto [l, r] = splitRank(c->right, rk - leftSize);
        c->right = l;
        c->upstream();
        return {c, r};
    }
    else
    {
        auto [l, r] = splitRank(c->left, rk);
        c->left = r;
        c->upstream();
        return {l, c};
    }
}
void output(node *c, std::vector<int> &v)
{
    c->downstream();
    if (c->left != nullptr)
    {
        output(c->left, v);
    }
    v.push_back(c->x);
    if (c->right != nullptr)
    {
        output(c->right, v);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        node *c = new node;
        c->x = s[i];
        root = merge(root, c);
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        auto [l, r] = splitRank(root, x);
        l->rev ^= true;
        root = merge(l, r);
    }
    std::vector<int> answer;
    output(root, answer);
    for (const auto &val : answer)
    {
        printf("%c", val);
    }
    printf("\n");
    return 0;
}
