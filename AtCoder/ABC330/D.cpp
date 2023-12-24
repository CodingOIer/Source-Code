#include <cstdio>
const int MaxN = 2e3 + 5;
int n;
char s[MaxN][MaxN];
long long sum[MaxN][MaxN];
long long answer;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] == 'o' ? 1 : 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i][j] == 'x')
            {
                continue;
            }
            int up, down, left, right;
            up = sum[i - 1][j] - sum[i - 1][j - 1];
            down = sum[n][j] - sum[i][j] - sum[n][j - 1] + sum[i][j - 1];
            left = sum[i][j - 1] - sum[i - 1][j - 1];
            right = sum[i][n] - sum[i - 1][n] - sum[i][j] + sum[i - 1][j];
            answer += up * right + right * down + down * left + left * up;
        }
    }
    printf("%lld\n", answer);
    return 0;
}