#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
int n;
std::priority_queue<long long> queue;
std::vector<std::tuple<int, int>> v;
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back({x, y});
    }
    std::sort(v.begin(), v.end());
    int answer = 0;
    long long cost = 0;
    for (const auto &[y, x] : v)
    {
        cost += x;
        queue.push(x);
        answer++;
        if (cost > y)
        {
            answer--;
            cost -= queue.top();
            queue.pop();
        }
    }
    printf("%d\n", answer);
}
