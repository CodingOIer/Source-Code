#include <cstdio>
#include <cstdlib>
constexpr int MaxN = 1e6 + 5;
int n;
int p[MaxN];
inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (abs(p[i] - p[i + 1]) == 5 || abs(p[i] - p[i + 1]) == 7)
        {
            // nothing
        }
        else
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
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