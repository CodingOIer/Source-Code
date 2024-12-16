#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e4 + 5;
int n;
long long hp, attack;
long long dp[2][MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%lld%lld", &hp, &attack);
    attack /= 10;
    long long maxAttack, minDistance;
    maxAttack = 0;
    minDistance = 0x3f3f3f3'3f3f3f3;
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = dp[1][i] = -0x3f3f3f3f'3f3f3f3f;
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i + j > n)
            {
                continue;
            }
            dp[i & 1][j] = 0;
            if (i != 0)
            {
                dp[i & 1][j] = std::max(dp[i & 1][j], dp[(i & 1) ^ 1][j] + 8 * attack + (i - 1) * attack * (j + 1));
            }
            if (j != 0)
            {
                dp[i & 1][j] = std::max(dp[i & 1][j], dp[i & 1][j - 1] + 7 * attack + i * attack * j);
            }
            long long nowAttack = dp[i & 1][j];
            long long sk = std::max(hp - nowAttack, 0ll);
            minDistance = 12 * attack + (6 + j) * i * attack == 0
                              ? 0x3f3f3ff'3f3f3f3f
                              : std::min(minDistance, i + j +
                                                          (sk + 12 * attack + (6 + j) * i * attack - 1) /
                                                              (12 * attack + (6 + j) * i * attack));
            maxAttack = std::max(maxAttack, nowAttack + (n - i - j) * (12 * attack + (6 + j) * i * attack));
        }
    }
    if (minDistance <= n)
    {
        printf("%lld\n", minDistance);
        printf("Tech Otakus Save The World!\n");
    }
    else
    {
        printf("%lld\n", maxAttack);
        printf("MiHoYo Was Destroyed!\n");
    }
    return 0;
}
