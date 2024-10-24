#include <algorithm>
#include <cstdio>
int n, k;
int p[1005];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%*d");
    }
    for (int i = k + 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d ", x);
    }
    for (int i = 1; i <= std::min(k, n); i++)
    {
        printf("0 ");
    }
    return 0;
}