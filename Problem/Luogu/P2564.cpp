#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <random>
#include <tuple>
#include <vector>
std::mt19937_64 rnd(std::random_device{}());
constexpr int MaxN = 1e6 + 5;
int n, k;
unsigned long long use[MaxN];
std::priority_queue<std::tuple<int, int, unsigned long long>, std::vector<std::tuple<int, int, unsigned long long>>,
                    std::greater<>>
    queue;
std::vector<std::tuple<int, int, unsigned long long>> v;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        int t;
        scanf("%d", &t);
        for (int j = 1; j <= t; j++)
        {
            int x;
            scanf("%d", &x);
            v.push_back({x, i, rnd()});
        }
    }
    std::sort(v.begin(), v.end());
    int miss = k;
    auto it = v.begin();
    int answer = 0x7f7f7f7f;
    for (; it != v.end();)
    {
        int now = std::get<0>(*it);
        for (; it != v.end();)
        {
            if (std::get<0>(*it) != now)
            {
                break;
            }
            miss -= use[std::get<1>(*it)] == 0 ? 1 : 0;
            use[std::get<1>(*it)] = std::get<2>(*it);
            queue.push({std::get<0>(*it), std::get<1>(*it), std::get<2>(*it)});
            it++;
        }
        for (; !queue.empty() && use[std::get<1>(queue.top())] != std::get<2>(queue.top());)
        {
            queue.pop();
        }
        if (miss == 0)
        {
            answer = std::min(answer, now - std::get<0>(queue.top()));
        }
    }
    printf("%d\n", answer);
    return 0;
}
