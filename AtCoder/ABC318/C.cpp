#include <algorithm>
#include <cstdio>
#include <queue>
const int MaxN = 2e5 + 5;
int n;
int w;
int d, p;
int f[MaxN];
long long answer;
std::priority_queue<int> queue;
int main()
{
    scanf("%d%d%d", &n, &d, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
        queue.push(f[i]);
    }
    for (; !queue.empty();)
    {
        long long sum;
        sum = 0;
        for (int i = 1; i <= d && !queue.empty(); i++)
        {
            sum += queue.top();
            queue.pop();
        }
        if (sum > p)
        {
            answer += p;
        }
        else
        {
            answer += sum;
        }
    }
    printf("%lld\n", answer);
    return 0;
}