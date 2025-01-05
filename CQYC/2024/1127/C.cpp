// 50 =

#include <algorithm>
#include <cstdio>
#include <random>
#include <tuple>
#include <vector>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 2e5 + 5;
int n, base;
int a[MaxN];
int h[MaxN];
int wCnt[MaxN];
int preSum[MaxN];
long long dp[MaxN];
std::vector<std::tuple<int, int>> v;
std::vector<std::tuple<int, int>> r;
long long killCost(long long x, long long kill)
{
    return x == 0 ? x : (x + kill - 1) / kill - 1;
}
void solve(int i)
{
    long long sumCost = 0;
    for (int j = i - 1; j >= 1; j--)
    {
        dp[j] = std::min(dp[j], dp[i] + killCost(h[i], std::max(base, a[j])) * a[i] + sumCost);
        sumCost += killCost(h[j], std::max(base, a[n])) * a[j];
    }
}
int main()
{
    scanf("%d%d", &n, &base);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        r.push_back({x, y});
    }
    std::sort(r.begin(), r.end(), [](const std::tuple<int, int> &x, const std::tuple<int, int> &y) {
        return std::get<1>(x) > std::get<1>(y);
    });
    for (const auto &val : r)
    {
        if (std::get<1>(val) <= base)
        {
            base = std::max(std::get<0>(val), base);
            continue;
        }
        v.push_back(val);
    }
    std::sort(v.begin(), v.end());
    v.insert(v.begin(), {base, 0});
    n = v.size();
    for (int i = 1; i <= n; i++)
    {
        a[i] = std::get<0>(v[i - 1]);
        h[i] = std::get<1>(v[i - 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0x7f7f'7f7f'7f7f;
    }
    dp[n] = 0;
    solve(n);
    std::vector<int> t;
    for (int i = n; i >= std::max(0, n - 500); i--)
    {
        t.push_back(i);
    }
    for (int i = std::min(n, 500); i >= 1; i--)
    {
        t.push_back(i);
    }
    for (int i = 1; i <= 1500; i++)
    {
        t.push_back(rnd() % n + 1);
    }
    std::sort(t.begin(), t.end());
    t.erase(std::unique(t.begin(), t.end()), t.end());
    std::reverse(t.begin(), t.end());
    for (const auto &val : t)
    {
        solve(val);
    }
    printf("%lld\n", dp[1]);
    return 0;
}
