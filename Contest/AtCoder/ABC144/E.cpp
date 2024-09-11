#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define debug printf("Debug\n")
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int MaxN = 2e5 + 5;
long long n, k;
long long tx, ty;
long long answer;
long long x[MaxN];
long long y[MaxN];
// std::priority_queue<std::pair<long long, long long>> queue;
long long check(long long want)
{
    long long need;
    need = 0;
    for (long long i = 1; i <= n; i++)
    {
        if (x[i] * y[i] > want)
        {
            need += (x[i] * y[i] - want) / y[i] + (((x[i] * y[i] - want) % y[i] == 0) ? 0 : 1);
        }
    }
    return need;
}
int main()
{
    scanf("%lld%lld", &n, &k);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &x[i]);
    }
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &y[i]);
    }
    std::sort(x + 1, x + n + 1);
    std::sort(y + 1, y + n + 1, [](long long x, long long y) { return x > y; });
    // K <= 10^12 ---> TLE
    // I will kill you, AtCoder!
    // AtCoder will be notorious!
    // for (long long i = 1; i <= n; i++)
    // {
    //     queue.push(std::make_pair(x[i] * y[i], y[i]));
    // }
    // for (long long i = 1; i <= k; i++)
    // {
    //     tx = queue.top().first;
    //     ty = queue.top().second;
    //     queue.pop();
    //     tx -= ty;
    //     queue.push(std::make_pair(tx, ty));
    // }
    // printf("%lld", std::max(0ll, queue.top().first));
    long long l, r;
    l = 0;
    r = 1e12;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        if (check(mid) <= k)
        {
            answer = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld\n", answer);
    return 0;
}
/*
1 2 4
3 2 1
*/