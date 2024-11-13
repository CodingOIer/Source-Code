#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e1 + 5;
int t;
int n, x;
int a[MaxN];
int b[MaxN];
void solve()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    std::sort(a + 1, a + 1 + n);
    std::sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] + b[n - i + 1] > x)
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
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