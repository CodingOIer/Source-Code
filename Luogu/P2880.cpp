#include <algorithm>
#include <cmath>
#include <cstdio>
const int MaxN = 1e6 + 5;
int n, m;
int min[MaxN];
int p[MaxN][19];
int l[MaxN], r[MaxN];
int query_min(int l, int r)
{
    int len;
    len = log2(r - l + 1);
    return std::min(p[l][len], p[r - (1 << len) + 1][len]);
}
int query_max(int l, int r)
{
    int len;
    len = log2(r - l + 1);
    return std::max(p[l][len], p[r - (1 << len) + 1][len]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i][0]);
    }
    for (int j = 1; j <= 18; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            p[i][j] = std::min(p[i][j - 1], p[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
        min[i] = query_min(l[i], r[i]);
    }
    for (int j = 1; j <= 18; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            p[i][j] = std::max(p[i][j - 1], p[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", query_max(l[i], r[i]) - min[i]);
    }
    return 0;
}