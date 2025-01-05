#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
class node
{
  public:
    int l, r;
    int cover;
    bool all;
    node *left, *right;
    node()
    {
        l = r = cover = 0;
        all = false;
        left = right = nullptr;
    }
};
int n;
node *root;
std::vector<std::tuple<int, int, int>> v;
void clear(node *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }
    clear(ptr->left);
    clear(ptr->right);
    delete ptr;
}
int query(node *ptr, int l, int r)
{
    if (ptr == nullptr)
    {
        return 0;
    }
    if (ptr->all)
    {
        int lx, rx;
        lx = std::max(l, ptr->l);
        rx = std::min(r, ptr->r);
        return rx - lx + 1;
    }
    if (l <= ptr->l && ptr->r <= r)
    {
        return ptr->cover;
    }
    int mid = (ptr->l + ptr->r) / 2;
    int res = 0;
    if (l <= mid)
    {
        res += query(ptr->left, l, r);
    }
    if (mid < r)
    {
        res += query(ptr->right, l, r);
    }
    return res;
}
void cover(node *ptr, int l, int r)
{
    if (ptr->all)
    {
        return;
    }
    if (l <= ptr->l && ptr->r <= r)
    {
        clear(ptr->left);
        clear(ptr->right);
        ptr->left = nullptr;
        ptr->right = nullptr;
        ptr->cover = ptr->r - ptr->l + 1;
        ptr->all = true;
        return;
    }
    int mid = (ptr->l + ptr->r) / 2;
    if (l <= mid)
    {
        if (ptr->left == nullptr)
        {
            ptr->left = new node;
            ptr->left->l = ptr->l;
            ptr->left->r = mid;
        }
        cover(ptr->left, l, r);
    }
    if (mid < r)
    {
        if (ptr->right == nullptr)
        {
            ptr->right = new node;
            ptr->right->l = mid + 1;
            ptr->right->r = ptr->r;
        }
        cover(ptr->right, l, r);
    }
    ptr->cover = (ptr->left == nullptr ? 0 : ptr->left->cover) + (ptr->right == nullptr ? 0 : ptr->right->cover);
}
inline void end()
{
    v.clear();
    clear(root);
    root = nullptr;
}
inline void solve()
{
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        mx = std::max(mx, r);
        v.push_back({l, r, k});
    }
    root = new node;
    root->l = 1;
    root->r = mx;
    std::sort(v.begin(), v.end(), [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) {
        return std::get<1>(x) < std::get<1>(y) || (std::get<1>(x) == std::get<1>(y) && std::get<0>(x) < std::get<0>(y));
    });
    for (const auto &_ : v)
    {
        int l, r, k;
        std::tie(l, r, k) = _;
        int cl, cr;
        cl = l + k - 1;
        cr = r;
        int can = -1;
        for (; cl <= cr;)
        {
            int mid = (cl + cr) / 2;
            int use = query(root, l, mid);
            if ((mid - l + 1) - use >= k)
            {
                can = mid;
                int more = ((mid - l + 1) - use) - k;
                cr = mid - std::max(1, more);
            }
            else
            {
                int less = k - ((mid - l + 1) - use);
                cl = mid + std::max(1, less);
            }
        }
        if (can == -1)
        {
            printf("No\n");
            end();
            return;
        }
        cover(root, l, can);
    }
    printf("Yes\n");
    end();
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
