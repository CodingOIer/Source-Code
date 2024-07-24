#include <cstdio>
#include <map>
constexpr int MaxN = 1e3 + 5;
int t;
int n, m;
int p[MaxN];
int h[MaxN];
std::map<int, bool> map;
void solve()
{
    map.clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        map[p[i]] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &h[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (map[h[i]])
        {
            printf("YES\n");
            printf("1 %d\n", h[i]);
            return;
        }
    }
    printf("NO\n");
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}