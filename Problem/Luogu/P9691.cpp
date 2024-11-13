#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n, m;
long long p[MaxN];
long long dp[MaxN];
std::vector<std::tuple<int, int>> links;
std::priority_queue<std::tuple<long long, int>, std::vector<std::tuple<long long, int>>, std::greater<>> queue;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        links.push_back({l, r});
    }
    std::sort(links.begin(), links.end(), [](const std::tuple<int, int> &x, const std::tuple<int, int> &y) -> bool {
        return std::get<1>(x) < std::get<1>(y);
    });
    auto it = links.begin();
    int lit = 0;
    for (; !queue.empty();)
    {
        queue.pop();
    }
    queue.push({0, 0});
    for (int i = 1; i <= n + 1; i++)
    {
        for (; it != links.end() && std::get<1>(*it) < i;)
        {
            lit = std::max(lit, std::get<0>(*it));
            it++;
        }
        for (; !queue.empty() && std::get<1>(queue.top()) < lit;)
        {
            queue.pop();
        }
        dp[i] = std::get<0>(queue.top()) + p[i];
        queue.push({dp[i], i});
    }
    printf("%lld\n", dp[n + 1]);
    return 0;
}