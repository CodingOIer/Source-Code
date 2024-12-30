#include <algorithm>
#include <cmath>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n, m;
int block;
int p[MaxN];
int cnt[MaxN];
int answer[MaxN];
std::vector<std::tuple<int, int, int>> v;
int main()
{
    scanf("%d%d", &n, &m);
    block = m / sqrt(m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
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
                   : std::get<1>(x) / block < std::get<1>(y) / block;
    });
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt[p[i]]++;
        res += cnt[p[i]] == 1 ? 1 : 0;
    }
    int l, r;
    l = 1;
    r = 0;
    for (const auto &[wantL, wantR, id] : v)
    {
        for (; wantL < l;)
        {
            l--;
            cnt[p[l]]--;
            res -= cnt[p[l]] == 0 ? 1 : 0;
            p[l]++;
            cnt[p[l]]++;
            res += cnt[p[l]] == 1 ? 1 : 0;
        }
        for (; r < wantR;)
        {
            r++;
            cnt[p[r]]--;
            res -= cnt[p[r]] == 0 ? 1 : 0;
            p[r]++;
            cnt[p[r]]++;
            res += cnt[p[r]] == 1 ? 1 : 0;
        }
        for (; l < wantL;)
        {
            cnt[p[l]]--;
            res -= cnt[p[l]] == 0 ? 1 : 0;
            p[l]--;
            cnt[p[l]]++;
            res += cnt[p[l]] == 1 ? 1 : 0;
            l++;
        }
        for (; wantR < r;)
        {
            cnt[p[r]]--;
            res -= cnt[p[r]] == 0 ? 1 : 0;
            p[r]--;
            cnt[p[r]]++;
            res += cnt[p[r]] == 1 ? 1 : 0;
            r--;
        }
        answer[id] = res;
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}
