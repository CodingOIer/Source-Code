#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, l, r;
int p[MaxN];
std::priority_queue<int> queueGreat;
std::priority_queue<int, std::vector<int>, std::greater<>> queueLess;
void solve()
{
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (; !queueLess.empty(); queueLess.pop())
    {
    }
    for (; !queueGreat.empty(); queueGreat.pop())
    {
    }
    long long now = 0;
    for (int i = l; i <= r; i++)
    {
        queueGreat.push(p[i]);
        now += p[i];
    }
    for (int i = 1; i <= l - 1; i++)
    {
        queueLess.push(p[i]);
    }
    long long answer = now;
    for (int i = 1; i <= n; i++)
    {
        for (; !queueLess.empty() && !queueGreat.empty();)
        {
            now -= queueGreat.top();
            now += queueLess.top();
            queueGreat.pop();
            queueLess.pop();
            answer = std::min(answer, now);
        }
    }
    for (; !queueLess.empty(); queueLess.pop())
    {
    }
    for (; !queueGreat.empty(); queueGreat.pop())
    {
    }
    now = 0;
    for (int i = l; i <= r; i++)
    {
        queueGreat.push(p[i]);
        now += p[i];
    }
    for (int i = r + 1; i <= n; i++)
    {
        queueLess.push(p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (; !queueLess.empty() && !queueGreat.empty();)
        {
            now -= queueGreat.top();
            now += queueLess.top();
            queueGreat.pop();
            queueLess.pop();
            answer = std::min(answer, now);
        }
    }
    printf("%lld\n", answer);
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
