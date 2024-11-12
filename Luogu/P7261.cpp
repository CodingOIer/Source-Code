#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <tuple>
#include <vector>
constexpr int MaxN = 3e5 + 5;
int block;
int n, m, c;
int p[MaxN];
int have[MaxN];
int answer[MaxN];
std::multiset<std::tuple<int, int>> set;
std::vector<std::tuple<int, int, int>> v;
int main()
{
    scanf("%d%d", &n, &c);
    block = std::sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    scanf("%d", &m);
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
    for (int i = 1; i <= c; i++)
    {
        set.insert({0, i});
    }
    int l, r;
    l = r = 1;
    set.erase(set.find({have[p[1]], p[1]}));
    have[p[1]]++;
    set.insert({have[p[1]], p[1]});
    for (auto [wantL, wantR, id] : v)
    {
        for (; wantL < l;)
        {
            l--;
            set.erase(set.find({have[p[l]], p[l]}));
            have[p[l]]++;
            set.insert({have[p[l]], p[l]});
        }
        for (; r < wantR;)
        {
            r++;
            set.erase(set.find({have[p[r]], p[r]}));
            have[p[r]]++;
            set.insert({have[p[r]], p[r]});
        }
        for (; l < wantL;)
        {
            set.erase(set.find({have[p[l]], p[l]}));
            have[p[l]]--;
            set.insert({have[p[l]], p[l]});
            l++;
        }
        for (; wantR < r;)
        {
            set.erase(set.find({have[p[r]], p[r]}));
            have[p[r]]--;
            set.insert({have[p[r]], p[r]});
            r--;
        }
        auto [cnt, cid] = *set.rbegin();
        answer[id] = cnt > (r - l + 1) / 2 ? cid : -1;
    }
    for (int i = 1; i <= m; i++)
    {
        if (answer[i] == -1)
        {
            printf("no\n");
        }
        else
        {
            printf("yes %d\n", answer[i]);
        }
    }
    return 0;
}