#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
class node
{
  public:
    int v, c, s;
    node()
    {
        v = 0;
        c = 0;
        s = 0;
    }
    friend bool operator<(const node &__x, const node &__y)
    {
        return __x.v < __y.v || (__x.v == __y.v && __x.s > __y.s);
    }
};
int n, q;
std::vector<node> queue;
std::vector<std::tuple<int, int, int, int>> link[MaxN];
bool dfs(int x, int e, int fa)
{
    if (x == e)
    {
        return true;
    }
    for (auto k : link[x])
    {
        int to, v, c, s;
        std::tie(to, v, c, s) = k;
        if (to == fa)
        {
            continue;
        }
        node temp;
        temp.v = v;
        temp.c = c;
        temp.s = s;
        queue.push_back(temp);
        if (dfs(to, e, x))
        {
            return true;
        }
        queue.pop_back();
    }
    return false;
}
int solve(int x, int y, long long m)
{
    dfs(x, y, 0);
    std::sort(queue.begin(), queue.end());
    int min = 0x3f3f3f3f;
    for (auto x : queue)
    {
        if (m >= x.c)
        {
            m -= x.c;
            min = std::min(min, x.s);
        }
        else
        {
            min = std::min(min, x.v);
        }
    }
    queue.clear();
    return min;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y, v, c, s;
        scanf("%d%d%d%d%d", &x, &y, &v, &c, &s);
        link[x].push_back({y, v, c, s});
        link[y].push_back({x, v, c, s});
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        long long e;
        scanf("%d%d%lld", &a, &b, &e);
        printf("%d\n", solve(a, b, e));
    }
    return 0;
}