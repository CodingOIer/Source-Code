#include <cstdio>
constexpr int MaxN = 2e6 + 5;
int n, m;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", p[x]);
    }
    return 0;
}