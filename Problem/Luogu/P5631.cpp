#include <cstdio>
#include <numeric>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n, m;
int fd[MaxN];
std::vector<std::tuple<int, int, int>> edges;
int find(int x)
{
    return x == fd[x] ? x : fd[x] = find(fd[x]);
}
int main()
{
    scanf("%d%d", &n, &m);
    int maxValue = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back({u, v, w});
        maxValue = std::max(maxValue, w);
    }
    int l, r;
    l = 0;
    r = maxValue + 1;
    int res = -1;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        std::iota(fd + 1, fd + 1 + n, 1);
        for (const auto &[u, v, w] : edges)
        {
            if (w != mid)
            {
                fd[find(u)] = find(v);
            }
        }
        int root = find(1);
        bool suc = true;
        for (int i = 1; i <= n; i++)
        {
            if (find(i) != root)
            {
                suc = false;
                break;
            }
        }
        if (suc)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d\n", res);
    return 0;
}
