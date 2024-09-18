#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
constexpr int MaxN = 5e1 + 5;
int n;
int p[MaxN];
int t[MaxN];
long long k, d;
long long rm[MaxN];
long long dp[MaxN];
std::priority_queue<std::tuple<long long, int, int>> best;
std::priority_queue<std::tuple<long long, int>> queue[MaxN];
int main()
{
    scanf("%d%lld%lld", &n, &k, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            dp[i] = 0;
        }
        else
        {
            std::queue<int> again;
            for (; !best.empty();)
            {
                auto [x, y, z] = best.top();
                if (y < i)
                {
                    again.push(z);
                    best.pop();
                }
                else
                {
                    dp[i] = x + p[i];
                    break;
                }
            }
            for (; !again.empty();)
            {
                int x = again.front();
                again.pop();
                for (;;)
                {
                    auto [a, b] = queue[x].top();
                    queue[x].pop();
                    if (b >= i)
                    {
                        best.push({a - rm[x], b, x});
                        break;
                    }
                }
            }
        }
        queue[i % k].push({dp[i] + rm[i % k], i + t[i]});
        rm[i - k < 0 ? n + i - k : i - k] += d;
    }
    printf("%lld\n", dp[n]);
    return 0;
}