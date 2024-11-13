#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n, m;
int block;
int p[MaxN];
int b[MaxN];
int have[MaxN];
int answer[MaxN];
std::vector<std::tuple<int, int, int>> change;
std::vector<std::tuple<int, int, int, int>> v;
int main()
{
    scanf("%d%d", &n, &m);
    block = pow(n, 2.0 / 3);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        b[i] = p[i];
    }
    for (int i = 1; i <= m; i++)
    {
        char op;
        scanf(" ");
        scanf("%c", &op);
        if (op == 'R')
        {
            int x, y;
            scanf("%d%d", &x, &y);
            change.push_back({x, y, b[x]});
            b[x] = y;
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            v.push_back({l, r, change.size(), v.size() + 1});
        }
    }
    std::sort(v.begin(), v.end(),
              [](const std::tuple<int, int, int, int> &x, const std::tuple<int, int, int, int> &y) -> bool {
                  return std::get<0>(x) / block == std::get<0>(y) / block
                             ? (std::get<1>(x) / block == std::get<1>(y) / block
                                    ? (std::get<2>(x) == std::get<2>(y) ? false : std::get<0>(x) / block % 2 == 1) ^
                                          (std::get<2>(x) < std::get<2>(y))
                                    : std::get<1>(x) / block < std::get<1>(y) / block)
                             : std::get<0>(x) / block < std::get<0>(y) / block;
              });
    int l, r, cur;
    l = r = 1;
    cur = 0;
    int res = 1;
    have[p[1]]++;
    for (auto [wantL, wantR, wantC, id] : v)
    {
        for (; wantL < l;)
        {
            l--;
            have[p[l]]++;
            res += have[p[l]] == 1 ? 1 : 0;
        }
        for (; r < wantR;)
        {
            r++;
            have[p[r]]++;
            res += have[p[r]] == 1 ? 1 : 0;
        }
        for (; l < wantL;)
        {
            have[p[l]]--;
            res -= have[p[l]] == 0 ? 1 : 0;
            l++;
        }
        for (; wantR < r;)
        {
            have[p[r]]--;
            res -= have[p[r]] == 0 ? 1 : 0;
            r--;
        }
        for (; cur < wantC;)
        {
            cur++;
            int x, y, z;
            std::tie(x, y, z) = change[cur - 1];
            if (l <= x && x <= r)
            {
                have[p[x]]--;
                res -= have[p[x]] == 0 ? 1 : 0;
            }
            p[x] = y;
            if (l <= x && x <= r)
            {
                have[p[x]]++;
                res += have[p[x]] == 1 ? 1 : 0;
            }
        }
        for (; wantC < cur;)
        {
            int x, y, z;
            std::tie(x, y, z) = change[cur - 1];
            if (l <= x && x <= r)
            {
                have[p[x]]--;
                res -= have[p[x]] == 0 ? 1 : 0;
            }
            p[x] = z;
            if (l <= x && x <= r)
            {
                have[p[x]]++;
                res += have[p[x]] == 1 ? 1 : 0;
            }
            cur--;
        }
        answer[id] = res;
    }
    for (int i = 1; i <= int(v.size()); i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}