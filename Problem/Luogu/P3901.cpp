#include <algorithm>
#include <cmath>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, q;
int block;
int p[MaxN];
int ref[MaxN];
int have[MaxN];
int answer[MaxN];
std::vector<std::tuple<int, int, int>> v;
int main()
{
    scanf("%d%d", &n, &q);
    block = std::sqrt(n);
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
    std::sort(v.begin(), v.end(), [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) -> bool {
        return std::get<0>(x) / block == std::get<0>(y) / block
                   ? (std::get<1>(x) == std::get<1>(y) ? false : (std::get<0>(x) / block) % 2 == 1) ^
                         (std::get<1>(x) < std::get<1>(y))
                   : std::get<0>(x) / block < std::get<0>(y) / block;
    });
    int l, r;
    int res = 0;
    l = r = 1;
    have[p[1]] = 1;
    for (auto [wantL, wantR, id] : v)
    {
        for (; wantL < l;)
        {
            l--;
            have[p[l]]++;
            res += have[p[l]] == 2 ? 1 : 0;
        }
        for (; r < wantR;)
        {
            r++;
            have[p[r]]++;
            res += have[p[r]] == 2 ? 1 : 0;
        }
        for (; l < wantL;)
        {
            have[p[l]]--;
            res -= have[p[l]] == 1 ? 1 : 0;
            l++;
        }
        for (; wantR < r;)
        {
            have[p[r]]--;
            res -= have[p[r]] == 1 ? 1 : 0;
            r--;
        }
        answer[id] = res;
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%s\n", answer[i] == 0 ? "Yes" : "No");
    }
    return 0;
}