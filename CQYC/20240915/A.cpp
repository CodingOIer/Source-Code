#include <cstdio>
constexpr int MaxN = 5e2 + 5;
int n;
int a[MaxN];
int b[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    return 0;
}