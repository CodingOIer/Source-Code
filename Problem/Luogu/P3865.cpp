#include <algorithm>
#include <cmath>
#include <cstdio>
const int MaxN = 1e5 + 5;
int n, m;
int l, r;
int st[MaxN][25];
int query(int l, int r)
{
    int len;
    len = log2(r - l + 1);
    return std::max(st[l][len], st[r - (1 << len) + 1][len]);
}
int main()
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &st[i][0]);
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = std::max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}