#include <algorithm>
#include <cmath>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e4 + 5;
int n, m;
int block;
int p[MaxN];
int ref[MaxN];
long long cnt[MaxN];
long long answerA[MaxN];
long long answerB[MaxN];
std::vector<std::tuple<int, int, int>> v;
long long gcd(long long x, long long y)
{
    for (;;)
    {
        if (x == 0 || x == y)
        {
            return y;
        }
        else if (y == 0)
        {
            return x;
        }
        else if (x > y)
        {
            x %= y;
        }
        else if (y > x)
        {
            y %= x;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    block = sqrt(n);
    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        ref[p[i]] = ref[p[i]] == 0 ? ++idx : ref[p[i]];
        p[i] = ref[p[i]];
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v.push_back({l, r, i});
    }
    std::sort(v.begin(), v.end(), [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) -> bool {
        return std::get<0>(x) / block == std::get<0>(y) / block
                   ? (std::get<1>(x) == std::get<1>(y) ? false : std::get<0>(x) / block % 2 == 1) ^
                         (std::get<1>(x) < std::get<1>(y))
                   : std::get<0>(x) / block < std::get<0>(y) / block;
    });
    int l, r;
    l = r = 1;
    cnt[p[1]]++;
    long long canPlan;
    canPlan = 0;
    for (const auto &[wantL, wantR, id] : v)
    {
        for (; wantL < l;)
        {
            l--;
            canPlan -= cnt[p[l]] * (cnt[p[l]] - 1);
            cnt[p[l]]++;
            canPlan += cnt[p[l]] * (cnt[p[l]] - 1);
        }
        for (; r < wantR;)
        {
            r++;
            canPlan -= cnt[p[r]] * (cnt[p[r]] - 1);
            cnt[p[r]]++;
            canPlan += cnt[p[r]] * (cnt[p[r]] - 1);
        }
        for (; l < wantL;)
        {
            canPlan -= cnt[p[l]] * (cnt[p[l]] - 1);
            cnt[p[l]]--;
            canPlan += cnt[p[l]] * (cnt[p[l]] - 1);
            l++;
        }
        for (; wantR < r;)
        {
            canPlan -= cnt[p[r]] * (cnt[p[r]] - 1);
            cnt[p[r]]--;
            canPlan += cnt[p[r]] * (cnt[p[r]] - 1);
            r--;
        }
        if (l == r)
        {
            answerA[id] = 0;
            answerB[id] = 1;
            continue;
        }
        long long length = r - l + 1;
        long long allPlan;
        allPlan = length * (length - 1);
        long long g = gcd(canPlan, allPlan);
        answerA[id] = canPlan / g;
        answerB[id] = allPlan / g;
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%lld/%lld\n", answerA[i], answerB[i]);
    }
    return 0;
}
