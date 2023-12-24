#include <bits/stdc++.h>
const int MaxN = 1e2 + 5;
int t;
int n;
int c[MaxN], b[MaxN];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &c[i], &b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] < c[i - 1] || b[i] < b[i - 1] || c[i] < b[i] || c[i] - c[i - 1] < b[i] - b[i - 1])
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
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