// 100pts
#include <algorithm>
#include <cstdio>
#include <queue>
constexpr int MaxN = 1e6 + 5;
int n;
int p[MaxN];
int dp[MaxN][3];
std::priority_queue<int> queue[3][3];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = 1;
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            queue[i][j].push(0);
        }
    }
    queue[p[1] % 3][0].push(dp[1][0]);
    queue[p[1] % 3][1].push(dp[1][1]);
    queue[p[1] % 3][2].push(dp[1][2]);
    int answer = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = 1 + std::max({queue[((p[i] + 3) - 0) % 3][0].top()});
        dp[i][1] = 1 + std::max({queue[((p[i] + 3) - 1) % 3][0].top(), queue[((p[i] + 3) - 1) % 3][1].top()});
        dp[i][2] = 1 + std::max({queue[((p[i] + 3) - 2) % 3][0].top(), queue[((p[i] + 3) - 2) % 3][1].top(),
                                 queue[((p[i] + 3) - 2) % 3][2].top()});
        dp[i][2] = std::max({dp[i][0], dp[i][1], dp[i][2]});
        dp[i][1] = std::max({dp[i][0], dp[i][1]});
        dp[i][0] = std::max({dp[i][0]});
        answer = std::max({answer, dp[i][0], dp[i][1], dp[i][2]});
        queue[p[i] % 3][0].push(dp[i][0]);
        queue[p[i] % 3][1].push(dp[i][1]);
        queue[p[i] % 3][2].push(dp[i][2]);
    }
    printf("%d\n", answer);
    return 0;
}