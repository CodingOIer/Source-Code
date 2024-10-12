#include <cmath>
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int n, R, r;
int x[MaxN];
int y[MaxN];
std::vector<int> v;
inline double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
inline void solve()
{
    v.clear();
    scanf("%d%d%d", &n, &R, &r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    if (r >= R / 2.0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dis(0, 0, x[i], y[i]) <= r - R / 2.0)
            {
                v.push_back(i);
            }
        }
        if (v.size() != 0)
        {
            printf("%zu\n", v.size());
            for (int i = 0; i < int(v.size()); i++)
            {
                printf("%d%c", v[i], i == (int(v.size()) - 1) ? '\n' : ' ');
            }
            return;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (dis(0, 0, x[i], y[i]) <= R - r / 2.0)
            {
                v.push_back(i);
            }
        }
        if (v.size() != 0)
        {
            printf("%zu\n", v.size());
            for (int i = 0; i < int(v.size()); i++)
            {
                printf("%d%c", v[i], i == (int(v.size()) - 1) ? '\n' : ' ');
            }
            return;
        }
    }
    v.clear();
    double best = 1e7;
    for (int i = 1; i <= n; i++)
    {
        if (dis(0, 0, x[i], y[i]) < best)
        {
            v.clear();
            v.push_back(i);
            best = dis(0, 0, x[i], y[i]);
        }
        else if (dis(0, 0, x[i], y[i]) == best)
        {
            v.push_back(i);
        }
    }
    printf("%zu\n", v.size());
    for (int i = 0; i < int(v.size()); i++)
    {
        printf("%d%c", v[i], i == (int(v.size()) - 1) ? '\n' : ' ');
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}