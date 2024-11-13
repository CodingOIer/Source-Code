#include <algorithm>
#include <cerrno>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int x1[MaxN];
int y1[MaxN];
int x2[MaxN];
int y2[MaxN];
int len[MaxN * 8];
int cover[MaxN * 8];
std::vector<int> v1;
std::vector<int> v2;
std::vector<std::tuple<bool, int, int>> v[MaxN];
inline int rex(int x)
{
    return std::lower_bound(v1.begin(), v1.end(), x) - v1.begin() + 1;
}
inline int fex(int x)
{
    return v1[x - 1];
}
inline int rey(int x)
{
    return std::lower_bound(v2.begin(), v2.end(), x) - v2.begin() + 1;
}
inline int fey(int x)
{
    return v2[x - 1];
}
inline void upstream(int c, int s, int t)
{
    if (cover[c] > 0)
    {
        len[c] = fey(t + 1) - fey(s);
    }
    else if (s == t)
    {
        len[c] = 0;
    }
    else
    {
        len[c] = len[c * 2] + len[c * 2 + 1];
    }
}
void change(int c, int s, int t, int l, int r, int val)
{
    if (l <= s && t <= r)
    {
        cover[c] += val;
        upstream(c, s, t);
        return;
    }
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change(c * 2 + 1, mid + 1, t, l, r, val);
    }
    upstream(c, s, t);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        v1.push_back(x1[i]);
        v1.push_back(x2[i]);
        v2.push_back(y1[i]);
        v2.push_back(y2[i]);
    }
    std::sort(v1.begin(), v1.end());
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
    std::sort(v2.begin(), v2.end());
    v2.erase(std::unique(v2.begin(), v2.end()), v2.end());
    for (int i = 1; i <= n; i++)
    {
        x1[i] = rex(x1[i]);
        x2[i] = rex(x2[i]);
        y1[i] = rey(y1[i]);
        y2[i] = rey(y2[i]);
        v[x1[i]].push_back({true, y1[i], y2[i]});
        v[x2[i]].push_back({false, y1[i], y2[i]});
    }
    long long last = fex(1);
    long long answer = 0;
    for (int px = 1; px <= int(v1.size()); px++)
    {
        answer += (fex(px) - last) * len[1];
        last = fex(px);
        for (auto [type, l, r] : v[px])
        {
            if (type)
            {
                change(1, 1, v2.size(), l, r - 1, 1);
            }
            else
            {
                change(1, 1, v2.size(), l, r - 1, -1);
            }
        }
    }
    printf("%lld\n", answer);
    return 0;
}