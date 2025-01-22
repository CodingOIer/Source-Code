#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, q;
int p[MaxN];
int sum[MaxN];
int have[MaxN];
int lastMore[MaxN];
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        lastMore[i] = p[i] > 0 ? i : lastMore[i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] > 0)
        {
            int suffixSum = 0;
            for (int j = 1; j <= i; j++)
            {
                suffixSum += p[i - j + 1];
                if (suffixSum <= 0 || (p[i - j + 1] > 0 && j != 1))
                {
                    break;
                }
                have[i] = j;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + have[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (lastMore[l] == 0 || lastMore[l] > r)
        {
            printf("0\n");
            continue;
        }
        int answer = sum[r] - sum[l - 1];
        if (lastMore[l] <= r && lastMore[l] != 0)
        {
            if (lastMore[l] - have[lastMore[l]] + 1 < l)
            {
                answer -= l - (lastMore[l] - have[lastMore[l]] + 1);
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
