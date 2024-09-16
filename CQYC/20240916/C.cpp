#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
constexpr int MaxN = 5e5 + 5;
int n;
int t[MaxN];
long long k, d;
long long p[MaxN];
std::queue<std::tuple<long long, long long, long long>> temp;
std::priority_queue<std::tuple<long long, long long, long long>> queue;
int main()
{
    freopen("holiday.in", "r", stdin);
    freopen("holiday.out", "w", stdout);
    scanf("%d%lld%lld", &n, &k, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &t[i]);
    }
    queue.push({0, 1, 1});
    long long best = -0x7f7f7f7f7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        best = -0x7f7f7f7f7f7f7f7f;
        for (; !queue.empty() && temp.size() <= 1e2;)
        {
            long long x;
            long long last, pre;
            std::tie(x, last, pre) = queue.top();
            queue.pop();
            if (last < i)
            {
                continue;
            }
            temp.push({x, last, pre});
            if (x < best)
            {
                break;
            }
            x -= (i - pre) / k * d;
            best = std::max(best, x);
        }
        // fprintf(stderr, "Solve %d in %zu count.\n", i, temp.size());
        best += p[i];
        for (; !temp.empty();)
        {
            queue.push(temp.front());
            temp.pop();
        }
        queue.push({best, i + t[i], i});
    }
    printf("%lld\n", best);
    return 0;
}