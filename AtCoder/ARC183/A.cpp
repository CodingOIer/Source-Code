#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
constexpr int MaxN = 5e2 + 5;
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    if (n % 2 == 0)
    {
        printf("%d", n / 2);
        for (int i = n; i >= 1; i--)
        {
            if (i == n / 2)
            {
                for (int j = 1; j <= k - 1; j++)
                {
                    printf(" %d", i);
                }
            }
            else
            {
                for (int j = 1; j <= k; j++)
                {
                    printf(" %d", i);
                }
            }
        }
    }
    else if (n % 2 == 1)
    {
        int w = n / 2 + 1;
        for (int i = 1; i <= k; i++)
        {
            printf("%d ", w);
        }
        if (w != 1)
        {
            printf("%d", w - 1);
            for (int i = n; i >= w + 1; i--)
            {
                for (int j = 1; j <= k; j++)
                {
                    printf(" %d", i);
                }
            }
            for (int i = w - 1; i >= 1; i--)
            {
                for (int j = 1; j <= k - (i == w - 1 ? 1 : 0); j++)
                {
                    printf(" %d", i);
                }
            }
        }
    }
    printf("\n");
    return 0;
}