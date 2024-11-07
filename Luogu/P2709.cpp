#include <algorithm>
#include <cmath>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e4 + 5;
int n, q;
int block;
int p[MaxN];
int ref[MaxN];
long long have[MaxN];
long long answer[MaxN];
std::vector<std::tuple<int, int, int>> v;
int main()
{
    scanf("%d%d%*d", &n, &q);
    block = sqrt(n);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        ref[p[i]] = ref[p[i]] == 0 ? ++cnt : ref[p[i]];
        p[i] = ref[p[i]];
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v.push_back({l, r, i});
    }
    std::sort(v.begin(), v.end(), [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) {
        return std::get<0>(x) / block == std::get<0>(y) / block
                   ? (std::get<1>(x) == std::get<1>(y) ? false : (std::get<0>(x) / block) % 2 == 1) ^
                         (std::get<1>(x) < std::get<1>(y))
                   : std::get<0>(x) / block < std::get<0>(y) / block;
    });
    long long res = 1;
    int l, r;
    l = r = 1;
    res = 1;
    have[p[1]] = 1;
    for (auto [wantL, wantR, id] : v)
    {
        for (; wantL < l;)
        {
            l--;
            res -= have[p[l]] * have[p[l]];
            have[p[l]]++;
            res += have[p[l]] * have[p[l]];
        }
        for (; r < wantR;)
        {
            r++;
            res -= have[p[r]] * have[p[r]];
            have[p[r]]++;
            res += have[p[r]] * have[p[r]];
        }
        for (; l < wantL;)
        {
            res -= have[p[l]] * have[p[l]];
            have[p[l]]--;
            res += have[p[l]] * have[p[l]];
            l++;
        }
        for (; wantR < r;)
        {
            res -= have[p[r]] * have[p[r]];
            have[p[r]]--;
            res += have[p[r]] * have[p[r]];
            r--;
        }
        answer[id] = res;
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%lld\n", answer[i]);
    }
    return 0;
}