#include <algorithm>
#include <cstdio>
#include <tuple>
#include <utility>
#include <vector>
constexpr int MaxN = 1e5 + 5;
class node
{
  public:
    int len;
    int all;
    int cover;
    node *left;
    node *right;
    node()
    {
        left = nullptr;
        right = nullptr;
        len = 0;
        all = 0;
        cover = 0;
    }
};
int n;
node *root;
std::vector<int> sk;
std::vector<std::pair<int, std::tuple<int, int, int>>> v;
inline int lk(int x)
{
    return std::lower_bound(sk.begin(), sk.end(), x) - sk.begin();
}
void build(node *c, int s, int t)
{
    if (s + 1 == t)
    {
        c->len = sk[t] - sk[s];
        return;
    }
    c->left = new node;
    c->right = new node;
    int mid = (s + t) / 2;
    build(c->left, s, mid);
    build(c->right, mid, t);
    c->len = c->left->len + c->right->len;
}
void change(node *c, int s, int t, int l, int r, int v)
{
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        v.push_back({y1, {x1, x2, 1}});
        v.push_back({y2, {x1, x2, -1}});
        sk.push_back(x1);
        sk.push_back(x2);
    }
    std::sort(v.begin(), v.end());
    std::sort(sk.begin(), sk.end());
    auto se = std::unique(sk.begin(), sk.end());
    for (; sk.end() != se;)
    {
        sk.pop_back();
    }
    for (auto &k : v)
    {
        int a, b, c;
        std::tie(a, b, c) = k.second;
        a = lk(a);
        b = lk(b);
        k.second = {a, b, c};
    }
    root = new node;
    build(root, 0, sk.size() - 1);
    return 0;
}