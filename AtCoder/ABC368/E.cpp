#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 4e5 + 5;
class eve
{
  public:
    int x;
    int id;
    bool arrive;
    long long cur;
    eve(int a = 0, int b = 0, bool c = false, int d = 0)
    {
        x = a;
        id = d;
        cur = b;
        arrive = c;
    }
    friend bool operator<(const eve &x, const eve &y)
    {
        return x.cur < y.cur || (x.cur == y.cur && x.arrive && !y.arrive);
    }
};
int n, m;
long long x[MaxN];
long long d[MaxN];
std::vector<eve> events;
int main()
{
    scanf("%d%d%lld", &n, &m, &x[1]);
    for (int i = 1; i <= m; i++)
    {
        int a, b, s, t;
        scanf("%d%d%d%d", &a, &b, &s, &t);
        events.push_back({a, s, false, i});
        events.push_back({b, t, true, i});
    }
    std::sort(events.begin(), events.end());
    for (auto k : events)
    {
        if (!k.arrive)
        {
            x[k.id] = std::max(x[k.id], d[k.x] - k.cur);
        }
        else
        {
            d[k.x] = std::max(d[k.x], k.cur + x[k.id]);
        }
    }
    for (int i = 2; i <= m; i++)
    {
        printf("%lld ", x[i]);
    }
    printf("\n");
    return 0;
}