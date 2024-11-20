#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e6 + 5;
int n, l, r;
int p[MaxN];
long long dp[MaxN];
std::vector<long long> v[MaxN];
std::priority_queue<std::tuple<long long, int>> queue;
int main()
{
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    queue.push({-0x3f3f3f3f3f3f3f3f, 0x3f3f3f3f});
    dp[0] = p[0];
    v[l].push_back(dp[0]);
    for (int i = 1; i <= n; i++)
    {
        for (const auto &val : v[i])
        {
            queue.push({val, i + (r - l)});
        }
        for (; std::get<1>(queue.top()) < i;)
        {
            queue.pop();
        }
        dp[i] = std::get<0>(queue.top()) + p[i];
        v[i + l].push_back(dp[i]);
    }
    long long answer = -0x7f7f7f7f7f7f7f7f;
    for (int i = std::max(0, n - r + 1); i <= n; i++)
    {
        answer = std::max(answer, dp[i]);
    }
    printf("%lld\n", answer);
    return 0;
}
