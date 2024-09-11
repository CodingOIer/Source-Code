#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e3 + 5;
int n, l;
int ans;
int p[MaxN];
bool cmp(int x, int y)
{
    return abs(x) < abs(y);
}
int main()
{
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = l + i - 1;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 2; i <= n; i++)
    {
        ans += p[i];
    }
    printf("%d\n", ans);
    return 0;
}