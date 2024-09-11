#include <cstdio>
int n, k;
int p[105];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = n - k + 1; i <= n; i++)
    {
        printf("%d ", p[i]);
    }
    for (int i = 1; i < n - k + 1; i++)
    {
        printf("%d ", p[i]);
    }
    return 0;
}