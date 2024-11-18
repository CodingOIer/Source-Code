#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int n, k;
int p[MaxN];
int b[MaxN];
int c[MaxN];
int can[MaxN];
long long sum[MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        can[i] = p[i] / b[i];
    }
    for (int i = n; i >= 1; i--)
    {
        sum[i] = sum[i + 1] + can[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (sum[i] < k)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("0 ");
            }
            printf("\n");
            return 0;
        }
        c[i] = std::max(0ll, k - sum[i + 1]);
        k -= c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
    return 0;
}
