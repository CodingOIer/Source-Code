#include <algorithm>
#include <cstdio>
const int MaxN = 2e6 + 5;
int x;
int n, m;
int p[MaxN];
int solve(int l, int r, int id)
{
    if (l == r)
    {
        return 1;
    }
    else if (id - l + 1 < r - id + 1)
    {
        return 1 + solve(l, id, id);
    }
    else
    {
        return 1 + solve(id - 1, r, id);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        printf("%d\n", solve(1, n, (int)(std::lower_bound(p + 1, p + 1 + n, x) - p)));
    }
    return 0;
}