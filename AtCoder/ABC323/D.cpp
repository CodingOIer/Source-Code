#include <algorithm>
#include <cstdio>
#include <queue>
#include <unordered_map>
#include <vector>
const int MaxN = 1e5 + 5;
long long n;
long long with;
long long s[MaxN], c[MaxN];
std::unordered_map<long long, long long> ball;
std::priority_queue<long long, std::vector<long long>, std::greater<long long>> queue;
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &s[i], &c[i]);
        with += c[i];
        ball[s[i]] = c[i];
        if (c[i] >= 1)
        {
            queue.push(s[i]);
        }
    }
    for (; !queue.empty();)
    {
        long long now = queue.top();
        queue.pop();
        long long make = ball[now] / 2;
        ball[now] -= 2 * make;
        if (make == 0)
        {
            continue;
        }
        with -= make;
        if (ball[2 * now] <= 1)
        {
            queue.push(2 * now);
        }
        ball[2 * now] += make;
    }
    printf("%lld\n", with);
    return 0;
}