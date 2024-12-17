#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n, k, q;
int p[MaxN];
std::priority_queue<long long, std::vector<long long>, std::greater<>> queue;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        for (; !queue.empty();)
        {
            queue.pop();
        }
        int x, y;
        scanf("%d%d", &x, &y);
        p[x] = y;
        std::sort(p + 1, p + 1 + n);
        long long answer = 0;
        for (int i = 1; i <= k; i++)
        {
            queue.push(0);
        }
        for (int i = 1; i <= n; i++)
        {
            auto x = queue.top();
            queue.pop();
            x += p[i];
            answer += x;
            queue.push(x);
        }
        printf("%lld\n", answer);
    }
    return 0;
}
