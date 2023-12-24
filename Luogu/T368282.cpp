#include <algorithm>
#include <cstdio>
const int MaxN = 1e5 + 5;
int t;
int n;
int a[MaxN];
int b[MaxN];
void solve()
{
    scanf("%d", &start);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &stop[i]);
    }
    scanf("%d", &end);
    year = end - start + 1;
    for (int i = 1; i <= n; i++)
    {
        if (start <= stop[i] && stop[i] <= end)
        {
            year--;
        }
    }
    printf("%d\n", year);
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