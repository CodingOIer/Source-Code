#include <cstdio>
constexpr int MaxN = 3e5 + 5;
int n;
int p[MaxN];
int q[MaxN];
int s[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &q[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        s[q[i]] = q[p[i]];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", s[i]);
    }
    printf("\n");
    return 0;
}
