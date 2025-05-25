#include <cstdio>
#include <queue>
constexpr int MaxN = 5e5 + 5;
int n;
long long answer;
long long p[MaxN];
std::priority_queue<long long> queue;
void solve()
{
    scanf("%d", &n);
    n *= 2;
    answer = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        answer += p[i];
        int can = i / 2;
        if (int(queue.size()) < can)
        {
            queue.push(p[i]);
        }
        else if (!queue.empty() && queue.top() > p[i])
        {
            queue.pop();
            queue.push(p[i]);
        }
    }
    for (; !queue.empty();)
    {
        answer -= queue.top();
        queue.pop();
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