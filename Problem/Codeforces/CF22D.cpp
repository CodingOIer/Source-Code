#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n;
int tree[MaxN];
std::vector<int> answer;
std::vector<std::tuple<int, int>> v;
void change(int x, int val)
{
    for (; x <= 1e5; x += x & -x)
    {
        tree[x] += val;
    }
}
int query(int x)
{
    int res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
bool query(int l, int r)
{
    return query(r) - query(l - 1) >= 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l > r)
        {
            std::swap(l, r);
        }
        v.push_back({l + 2e4, r + 2e4});
    }
    std::sort(v.begin(), v.end(), [](const std::tuple<int, int> &x, const std::tuple<int, int> &y) -> bool {
        return std::get<1>(x) < std::get<1>(y);
    });
    for (const auto &[l, r] : v)
    {
        if (query(l, r))
        {
            continue;
        }
        change(r, 1);
        answer.push_back(r - 2e4);
    }
    printf("%zu\n", answer.size());
    for (const auto &val : answer)
    {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}