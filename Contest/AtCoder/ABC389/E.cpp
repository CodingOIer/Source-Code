#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
long long m;
long long p[MaxN];
long long k[MaxN];
std::priority_queue<std::tuple<long long, int>, std::vector<std::tuple<long long, int>>, std::greater<>> queue;
int main()
{
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        queue.push({p[i], i});
    }
    int answer = 0;
    for (;;)
    {
    }
    printf("%d", answer);
    return 0;
}
