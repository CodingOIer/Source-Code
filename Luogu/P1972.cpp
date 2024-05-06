#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n, m;
int p[MaxN];
int f[MaxN];
std::vector<std::pair<int, int>> v;
bool cmp(std::pair<int, int> x, std::pair<int, int> y)
{
    if (x.first < y.first)
    {
        return true;
    }
    else if (x.first > y.first)
    {
        return false;
    }
    else
    {
        if (x.first % 2 == 1)
        {
            return x.second < y.second;
        }
        else
        {
            return x.second > y.second;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v.push_back({l, r});
    }
    std::sort(v.begin(), v.end(), cmp);
    int l, r, res;
    l = 1;
    r = 0;
    res = 0;
    for ()
        return 0;
}