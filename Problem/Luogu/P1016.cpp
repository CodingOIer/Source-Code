#include <algorithm>
#include <cstdio>
#include <set>
#include <tuple>
#include <vector>
int n;
double d, c, k, p;
std::vector<std::tuple<double, double>> v;
std::multiset<std::tuple<double, double>> oil;
int main()
{
    scanf("%lf%lf%lf%lf%d", &d, &c, &k, &p, &n);
    oil.insert({p, c});
    double last = 0;
    double allCost = 0;
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        v.push_back({x, y});
    }
    v.push_back({d, 1e9});
    std::sort(v.begin(), v.end());
    for (int i = 1; i <= n + 1; i++)
    {
        double cur, cost;
        std::tie(cur, cost) = v[i - 1];
        double costOil = (cur - last) / k;
        double add = costOil;
        for (; costOil > 0;)
        {
            if (oil.empty())
            {
                printf("No Solution\n");
                return 0;
            }
            auto [x, y] = *oil.begin();
            oil.erase(oil.begin());
            double use = std::min(y, costOil);
            allCost += use * x;
            y -= use;
            costOil -= use;
            if (y > 0)
            {
                oil.insert({x, y});
            }
        }
        for (;;)
        {
            if (oil.empty())
            {
                break;
            }
            auto [x, y] = *oil.rbegin();
            if (x > cost)
            {
                add += y;
                oil.erase(*oil.rbegin());
            }
            else
            {
                break;
            }
        }
        oil.insert({cost, add});
        last = cur;
    }
    printf("%.2lf\n", allCost);
    return 0;
}
