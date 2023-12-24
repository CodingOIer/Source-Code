#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e2 + 5;
int n;
int ans;
int p[5][MaxN];
void dfs(int x, int y, int sum)
{
    if (!(1 <= x && x <= 2 && 1 <= y && y <= n))
    {
        return;
    }
    sum += p[x][y];
    if (x == 2 && y == n)
    {
        ans = max(ans, sum);
    }
    dfs(x + 1, y, sum);
    dfs(x, y + 1, sum);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    dfs(1, 1, 0);
    printf("%d\n", ans);
    return 0;
}