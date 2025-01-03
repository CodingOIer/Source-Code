#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
constexpr int SubtaskSize = 3e4;
int n, m;
int p[MaxN];
int l1[MaxN];
int r1[MaxN];
int l2[MaxN];
int r2[MaxN];
int l3[MaxN];
int r3[MaxN];
int cnt[MaxN];
int have[MaxN];
int begin[MaxN];
std::vector<int> uq;
std::bitset<MaxN> f[SubtaskSize + 5];
std::vector<std::tuple<int, int, int>> v;
void solve()
{
    int block = sqrt(v.size());
    std::sort(v.begin(), v.end(), [&](const std::tuple<int, int, int> a, const std::tuple<int, int, int> b) {
        return std::get<0>(a) / block == std::get<0>(b) / block
                   ? (std::get<1>(a) == std::get<1>(b) ? false : std::get<0>(a) / block % 2 == 1) ^
                         (std::get<1>(a) < std::get<1>(b))
                   : std::get<0>(a) / block < std::get<0>(b) / block;
    });
    memset(have, 0, sizeof(have));
    int l, r;
    l = 1;
    r = 0;
    std::bitset<MaxN> res;
    for (const auto &[wantL, wantR, id] : v)
    {
        for (; wantL < l;)
        {
            l--;
            have[p[l]]++;
            res[begin[p[l]] + have[p[l]] - 1] = true;
        }
        for (; r < wantR;)
        {
            r++;
            have[p[r]]++;
            res[begin[p[r]] + have[p[r]] - 1] = true;
        }
        for (; l < wantL;)
        {
            res[begin[p[l]] + have[p[l]] - 1] = false;
            have[p[l]]--;
            l++;
        }
        for (; wantR < r;)
        {
            res[begin[p[r]] + have[p[r]] - 1] = false;
            have[p[r]]--;
            r--;
        }
        f[id] = res;
    }
    v.clear();
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        uq.push_back(p[i]);
    }
    std::sort(uq.begin(), uq.end());
    uq.erase(std::unique(uq.begin(), uq.end()), uq.end());
    for (int i = 1; i <= n; i++)
    {
        p[i] = std::lower_bound(uq.begin(), uq.end(), p[i]) - uq.begin() + 1;
        cnt[p[i]]++;
    }
    int prefixCnt = 0;
    for (int i = 1; i <= n; i++)
    {
        begin[i] = prefixCnt + 1;
        prefixCnt += cnt[i];
    }
    int cntOfMo = 0;
    int lastCalc = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d%d%d", &l1[i], &r1[i], &l2[i], &r2[i], &l3[i], &r3[i]);
        v.push_back({l1[i], r1[i], ++cntOfMo});
        v.push_back({l2[i], r2[i], ++cntOfMo});
        v.push_back({l3[i], r3[i], ++cntOfMo});
        if (cntOfMo >= SubtaskSize)
        {
            solve();
            int ck = 0;
            for (int j = lastCalc + 1; j <= i; j++)
            {
                int a, b, c;
                a = ++ck;
                b = ++ck;
                c = ++ck;
                printf("%zu\n", (f[a].count() + f[b].count() + f[c].count()) - 3 * (f[a] & f[b] & f[c]).count());
            }
            cntOfMo = 0;
            lastCalc = i;
        }
    }
    solve();
    int ck = 0;
    for (int j = lastCalc + 1; j <= m; j++)
    {
        int a, b, c;
        a = ++ck;
        b = ++ck;
        c = ++ck;
        printf("%zu\n", (f[a].count() + f[b].count() + f[c].count()) - 3 * (f[a] & f[b] & f[c]).count());
    }
    return 0;
}
