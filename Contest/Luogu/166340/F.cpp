#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
int a[MaxN];
int p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        if (!(1 <= p[i] && p[i] <= n) || a[p[i]] != 0)
        {
            printf("NO\n");
            return 0;
        }
        a[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] != a[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}