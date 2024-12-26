#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n;
long long p[MaxN];
long long answer[MaxN];
std::vector<std::tuple<long long, int>> v;
int main()
{
    scanf("%d", &n);
    long long maxValue = 0;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        scanf("%lld", &x);
        maxValue = std::max(maxValue, x);
        v.push_back({x, i});
    }
    std::sort(v.begin(), v.end());
    auto it = v.begin();
    for (; it != v.end() && std::get<0>(*it) == 1; it++)
    {
        answer[std::get<1>(*it)] = 1;
    }
    p[1] = 1;
    int now = 1;
    int have = 1;
    long long last = 1;
    for (long long i = 2; i <= maxValue; i++)
    {
        if (have == 0)
        {
            now++;
            have = now + 1;
        }
        have--;
        long long x = last + p[now];
        if (i <= 1e6)
        {
            p[i] = x;
        }
        for (; it != v.end() && std::get<0>(*it) == i; it++)
        {
            answer[std::get<1>(*it)] = x;
        }
        last = x;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", answer[i]);
    }
    return 0;
}
