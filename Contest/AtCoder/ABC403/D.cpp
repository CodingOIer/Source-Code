#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 5e6 + 5;
int n, d;
int answer;
int f[MaxN];
int dp[2][MaxN];
int main()
{
    scanf("%d%d", &n, &d);
    if (d == 0)
    {
        std::vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
        printf("%d\n", n - int(v.size()));
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        f[x]++;
    }
    for (int i = 0; i < d; i++)
    {
        int last = 0;
        for (int j = 0; i + j <= 1e6; j += d)
        {
            int c = j / d + 1;
            dp[0][c] = std::max(dp[0][c - 1], dp[1][c - 1]);
            dp[1][c] = dp[0][c - 1] + f[i + j];
            last = c;
        }
        answer += std::max(dp[0][last], dp[1][last]);
    }
    printf("%d\n", n - answer);
    return 0;
}