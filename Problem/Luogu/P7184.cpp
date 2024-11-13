#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 5e1 + 5;
int r, n;
int dp[128][MaxN][MaxN];
int score[128][128];
char s[MaxN];
char t[MaxN][MaxN];
std::vector<char> range = {'P', 'S', 'R'};
void init()
{
    score['P']['S'] = 0;
    score['R']['P'] = 0;
    score['S']['R'] = 0;
    score['S']['S'] = 1;
    score['P']['P'] = 1;
    score['R']['R'] = 1;
    score['S']['P'] = 2;
    score['P']['R'] = 2;
    score['R']['S'] = 2;
}
int main()
{
    init();
    scanf("%d", &r);
    scanf("%s", s + 1);
    scanf("%d", &n);
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", t[i] + 1);
        for (int j = 1; j <= r; j++)
        {
            answer += score[s[j]][t[i][j]];
        }
    }
    int max = 0;
    for (int i = 1; i <= r; i++)
    {
        int pre = max;
        for (auto x : range)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                cnt += score[x][t[j][i]];
            }
            max = std::max(pre + cnt, max);
        }
        pre = max;
    }
    printf("%d\n", answer);
    printf("%d\n", max);
    return 0;
}