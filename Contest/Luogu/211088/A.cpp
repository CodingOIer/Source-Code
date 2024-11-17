#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m;
std::vector<int> v[MaxN];
std::vector<std::tuple<int, int, int>> pr;
std::priority_queue<int, std::vector<int>, std::greater<>> can;
std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>, std::greater<>> queue;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        can.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int x, t;
        scanf("%d%d", &x, &t);
        pr.push_back({t, x, i});
    }
    std::sort(pr.begin(), pr.end());
    for (const auto &[t, x, pid] : pr)
    {
        for (; !queue.empty() && std::get<0>(queue.top()) <= t;)
        {
            can.push(std::get<1>(queue.top()));
            queue.pop();
        }
        if (!can.empty())
        {
            v[can.top()].push_back(pid);
            queue.push({t + x, can.top()});
            can.pop();
        }
        else
        {
            auto [cur, id] = queue.top();
            v[id].push_back(pid);
            queue.pop();
            cur += x;
            queue.push({cur, id});
        }
    }
    for (int i = 1; i <= m; i++)
    {
        std::sort(v[i].begin(), v[i].end());
        printf("%zu", v[i].size());
        for (const auto &val : v[i])
        {
            printf(" %d", val);
        }
        printf("\n");
    }
    return 0;
}
