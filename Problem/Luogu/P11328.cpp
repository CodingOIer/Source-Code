#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n;
int p[MaxN];
std::priority_queue<long long> queue;
std::vector<std::tuple<int, int>> v;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        v.push_back({p[i], x});
    }
    std::sort(v.begin(), v.end(), [](const std::tuple<int, int> &a, const std::tuple<int, int> &b) {
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
    return 0;
}
