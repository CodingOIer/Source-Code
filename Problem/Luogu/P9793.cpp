// 100

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <set>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n;
int f[MaxN];
int id[64][MaxN];
bool vi[MaxN];
long long p[MaxN];
long long vis[MaxN];
long long value[MaxN];
long long answer[MaxN];
std::set<int> v[65];
int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
inline void merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx == fy)
    {
        return;
    }
    f[fy] = fx;
    for (int j = 0; j < 63; j++)
    {
        if ((vis[fx] >> j) & 1 && (vis[fy] >> j & 1))
        {
            v[j].erase(id[j][fx]);
        }
        if (~(vis[fx] >> j) & 1 && (vis[fy] >> j & 1))
        {
            continue;
        }
        if ((vis[fx] >> j) & 1 && ~(vis[fy] >> j & 1))
        {
            id[j][fy] = id[j][fx];
        }
        if (~(vis[fx] >> j) & 1 && ~(vis[fy] >> j & 1))
        {
            continue;
        }
    }
    vis[fy] |= vis[fx];
}
inline int log2(long long x)
{
    int res = 0;
    for (; x != 0;)
    {
        res++;
        x /= 2;
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + 1 + n, [](const long long &__x, const long long &__y) -> bool { return __x > __y; });
    std::iota(f + 1, f + 1 + n, 1);
    for (int i = 1; i <= n; i++)
    {
        int w = log2(p[i]) - 1;
        std::vector<std::tuple<int, int>> temp;
        for (auto val : v[w])
        {
            temp.push_back(std::tuple<int, int>{val, i});
        }
        for (auto _ : temp)
        {
            int x, y;
            std::tie(x, y) = _;
            merge(x, y);
        }
        for (int j = 0; j < 63; j++)
        {
            if (~(p[i] >> j) & 1 && ~(vis[find(i)] >> j) & 1 && (1ll << j) <= p[i])
            {
                v[j].insert(find(i));
                id[j][find(i)] = find(i);
                vis[find(i)] |= 1ll << j;
            }
        }
        if (i >> 17 << 17 == i)
        {
            for (int j = 0; j < 63; j++)
            {
                std::vector<int> temp;
                for (auto val : v[j])
                {
                    temp.push_back(find(val));
                }
                v[j].clear();
                for (auto val : temp)
                {
                    v[j].insert(val);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &value[i]);
        answer[find(i)] += value[i];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", answer[find(i)]);
    }
    return 0;
}
