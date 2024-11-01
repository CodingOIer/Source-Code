#include <cstdio>
#include <map>
#include <tuple>
constexpr int MaxN = 2e5 + 5;
int n, x, y;
int p[MaxN];
std::map<std::tuple<int, int>, int> map;
inline void solve()
{
    map.clear();
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        map[{p[i] % x, p[i] % y}]++;
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        map[{p[i] % x, p[i] % y}]--;
        answer += map[{(x - p[i] % x) % x, p[i] % y}];
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