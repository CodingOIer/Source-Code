#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e2 + 5;
int n;
int p[MaxN];
int sum[MaxN];
int dp_max[MaxN][MaxN];
int dp_min[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        p[n + i] = p[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        sum[i] = sum[i - 1] + p[i];
    }
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i <= 2 * n - len + 1; i++)
        {
            int l, r;
            l = i;
            r = i + len - 1;
            if (len == 1)
            {
                dp_min[l][r] = 0;
                dp_max[l][r] = 0;
                continue;
            }
            dp_min[l][r] = 0x3f3f3f3f;
            dp_max[l][r] = -0x3f3f3f3f;
            for (int j = l; j <= r - 1; j++)
            {
                dp_max[l][r] =
                    std::max(dp_max[l][r], dp_max[l][j] + dp_max[j + 1][r] + (sum[j] - sum[l - 1]) + (sum[r] - sum[j]));
                dp_min[l][r] =
                    std::min(dp_min[l][r], dp_min[l][j] + dp_min[j + 1][r] + (sum[j] - sum[l - 1]) + (sum[r] - sum[j]));
            }
        }
    }
    int max = 0, min = 0x3f3f3f3f;
    for (int i = 1; i <= n + 1; i++)
    {
        min = std::min(min, dp_min[i][i + n - 1]);
        max = std::max(max, dp_max[i][i + n - 1]);
    }
    printf("%d\n", min);
    printf("%d\n", max);
    return 0;
}