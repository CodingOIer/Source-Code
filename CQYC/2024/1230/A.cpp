#include <cstdio>
#include <utility>
constexpr int MaxN = 1e6 + 5;
int n;
int p[MaxN];
void solve()
{
    scanf("%d", &n);
    if (n == 1)
    {
        printf("No\n");
        return;
    }
    if (n % 2 == 1)
    {
        for (int i = 1; i <= n; i += 4)
        {
            int w = (i + 3) / 4;
            p[i] = n / 2 + w;
            p[i + 2] = n - w + 1;
        }
        for (int i = 2; i <= n; i += 2)
        {
            int w = i / 2;
            p[i] = n / 2 - w + 1;
        }
        std::swap(p[n - 1], p[n]);
    }
    else if (n % 2 == 0)
    {
        p[1] = n / 2;
        for (int i = 2; i <= n; i += 4)
        {
            int w = (i + 2) / 4;
            p[i] = n / 2 + 1 + w - 1;
            p[i + 2] = n - w + 1;
        }
        for (int i = 3; i <= n; i += 2)
        {
            int w = (i - 1) / 2;
            p[i] = n / 2 - w;
        }
        std::swap(p[n - 1], p[n]);
    }
    printf("Yes\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
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
