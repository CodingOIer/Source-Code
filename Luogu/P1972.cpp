#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n, m;
int p[MaxN];
int q[MaxN];
int answer[MaxN];
std::vector<std::pair<std::pair<int, int>, int>> v;
inline bool cmp(std::pair<std::pair<int, int>, int> x, std::pair<std::pair<int, int>, int> y)
{
    if (x.first.first < y.first.first)
    {
        return true;
    }
    else if (x.first.first > y.first.first)
    {
        return false;
    }
    else
    {
        return x.first.second < y.first.second;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back({{x, y}, i});
    }
    std::sort(v.begin(), v.end(), cmp);
    auto k = v.begin();
    int l, r;
    l = 1;
    r = 1;
    int res = 1;
    q[p[1]]++;
    for (; k != v.end();)
    {
        for (; l < (*k).first.first;)
        {
            q[p[l]]--;
            if (q[p[l]] == 0)
            {
                res--;
            }
            if (q[p[l]] == 1)
            {
                res++;
            }
            l++;
        }
        for (; l > (*k).first.first;)
        {
            l--;
            q[p[l]]++;
            if (q[p[l]] == 0)
            {
                res--;
            }
            if (q[p[l]] == 1)
            {
                res++;
            }
        }
        for (; r < (*k).first.second;)
        {
            r++;
            q[p[r]]++;
            if (q[p[r]] == 0)
            {
                res--;
            }
            if (q[p[r]] == 1)
            {
                res++;
            }
        }
        for (; r > (*k).first.second;)
        {
            q[p[r]]--;
            if (q[p[r]] == 0)
            {
                res--;
            }
            if (q[p[r]] == 1)
            {
                res++;
            }
            r--;
        }
        answer[(*k).second] = res;
        k++;
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}