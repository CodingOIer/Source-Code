#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n, m;
int p[MaxN];
int use[MaxN];
std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>, std::greater<>> queue;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int miss = m;
    int l, r;
    l = r = -1;
    int answer = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        miss -= use[p[i]] == 0 ? 1 : 0;
        use[p[i]] = i;
        queue.push({i, p[i]});
        for (; use[std::get<1>(queue.top())] != std::get<0>(queue.top());)
        {
            queue.pop();
        }
        if (miss == 0)
        {
            if (i - std::get<0>(queue.top()) < answer)
            {
                answer = i - std::get<0>(queue.top());
                l = std::get<0>(queue.top());
                r = i;
            }
        }
    }
    printf("%d %d\n", l, r);
    return 0;
}
