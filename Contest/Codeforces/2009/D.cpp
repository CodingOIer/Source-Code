#include <cstdio>
#include <map>
#include <tuple>
constexpr int MaxN = 2e5 + 5;
int n;
int x[MaxN];
int y[MaxN];
std::map<std::tuple<int, int>, bool> map;
inline void solve()
{
    map.clear();
    int cnt0, cnt1;
    cnt0 = cnt1 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        if (y[i] == 0)
        {
            cnt0++;
        }
        else
        {
            cnt1++;
        }
        map[{x[i], y[i]}] = true;
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (y[i] == 0)
        {
            cnt0--;
        }
        else
        {
            cnt1--;
        }
        if (y[i] == 0)
        {
            answer += (map[{x[i], 1}] ? 1 : 0) * cnt0;
            answer += map[{x[i] - 1, 1}] && map[{x[i] + 1, 1}] ? 1 : 0;
        }
        else
        {
            answer += (map[{x[i], 0}] ? 1 : 0) * cnt1;
            answer += map[{x[i] - 1, 0}] && map[{x[i] + 1, 0}] ? 1 : 0;
        }
        if (y[i] == 0)
        {
            cnt0++;
        }
        else
        {
            cnt1++;
        }
    }
    printf("%lld\n", answer);
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
