#include <algorithm>
#include <cstdio>
class str
{
  public:
    int v;
    int val;
    bool operator<(const str a)
    {
        return (double)(val) / (double)(v) < (double)(a.val) / (double)(a.v);
    }
    bool operator>(const str a)
    {
        return (double)(val) / (double)(v) > (double)(a.val) / (double)(a.v);
    }
};
const int MaxN = 1e2 + 5;
int n;
int cnt;
int need;
int loser;
int winner;
int x[MaxN];
int y[MaxN];
int z[MaxN];
str dp[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        if (x[i] > y[i])
        {
            winner += z[i];
        }
        else if (x[i] < y[i])
        {
            loser += z[i];
            cnt++;
            dp[cnt].v = (y[i] - x[i]) / 2 + 1;
            dp[cnt].val = z[i];
        }
    }
    if (winner > loser)
    {
        printf("0\n");
    }
    else
    {
        need = (loser - winner) / 2 + 1;
        std::sort(dp + 1, dp + 1 + n, [](str a, str b) { return a > b; });
    }
    return 0;
}