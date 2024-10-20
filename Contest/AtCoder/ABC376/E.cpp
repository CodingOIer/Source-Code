#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
constexpr int MaxN = 2e2 + 5;
int n, k;
int x[MaxN];
int y[MaxN];
std::tuple<int, int> p[MaxN];
std::priority_queue<int> queue;
void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &y[i]);
        p[i] = {x[i], y[i]};
    }
    std::sort(p + 1, p + 1 + n);
    long long sum = 0;
    for (int i = 1; i <= k; i++)
    {
        queue.push(std::get<1>(p[i]));
        sum += std::get<1>(p[i]);
    }
    long long answer = std::get<0>(p[k]) * sum;
    for (int i = k + 1; i <= n; i++)
    {
        int x = queue.top();
        sum -= x;
        queue.pop();
        answer = std::min(answer, (sum + std::get<1>(p[i])) * std::get<0>(p[i]));
        queue.push(x);
        queue.push(std::get<1>(p[i]));
        sum += std::get<1>(p[i]);
        sum += x;
        sum -= queue.top();
        queue.pop();
    }
    printf("%lld\n", answer);
    for (; !queue.empty();)
    {
        queue.pop();
    }
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
