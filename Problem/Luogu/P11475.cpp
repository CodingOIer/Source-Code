#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
int n;
std::priority_queue<long long> queue;
std::vector<std::tuple<long long, long long>> v;
void solve()
{
    v.clear();
    for (; !queue.empty();)
    {
        queue.pop();
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        v.push_back({y, x});
    }
    std::sort(v.begin(), v.end(),
              [](const std::tuple<long long, long long> &a, const std::tuple<long long, long long> &b) {
                  return std::get<0>(a) + std::get<1>(a) < std::get<0>(b) + std::get<1>(b);
              });
    int answer = 0;
    long long cost = 0;
    for (const auto [x, y] : v)
    {
        if (cost <= y)
        {
            answer++;
            cost += x;
            queue.push(x);
        }
        else
        {
            cost += x;
            queue.push(x);
            cost -= queue.top();
            queue.pop();
        }
    }
    printf("%d\n", answer);
}
int main()
{
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
