#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int t;
int n;
int p[MaxN];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int w = 0;
    for (; p[w + 1] == 1 && w + 1 <= n;)
    {
        w++;
    }
    printf("%s\n", w != n ? (w % 2 == 1 ? "Second" : "First") : (w % 2 == 1 ? "First" : "Second"));
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