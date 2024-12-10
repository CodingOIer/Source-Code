#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e1 + 5;
int n;
int answer;
int cnt[MaxN];
int length[MaxN];
int dis[MaxN][MaxN];
char s[MaxN][MaxN];
int calcDis(int from, int to)
{
    if (dis[from][to] != -1)
    {
        return dis[from][to];
    }
    int lenFrom, lenTo;
    lenFrom = length[from];
    lenTo = length[to];
    int res = 0;
    for (int i = 1; i <= std::min(lenFrom, lenTo) - 1; i++)
    {
        bool suc = true;
        for (int k = 1; k <= i; k++)
        {
            suc &= s[from][lenFrom - i + k] == s[to][k];
        }
        if (suc)
        {
            res = i;
            break;
        }
    }
    dis[from][to] = res;
    return res;
}
void dfs(int before, int now)
{
    answer = std::max(answer, now);
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            continue;
        }
        int same = calcDis(before, i);
        if (same == 0)
        {
            continue;
        }
        cnt[i]--;
        dfs(i, now + length[i] - same);
        cnt[i]++;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 2;
        scanf("%s", s[i] + 1);
        length[i] = strlen(s[i] + 1);
    }
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            dis[i][j] = -1;
        }
    }
    s[n + 1][1] = '@';
    scanf("%s", s[n + 1] + 2);
    length[n + 1] = strlen(s[n + 1] + 1);
    dfs(n + 1, length[n + 1] - 1);
    printf("%d\n", answer);
    return 0;
}
