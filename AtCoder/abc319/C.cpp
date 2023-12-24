#include <cstdio>
const int MaxN = 15;
int n;
int bad;
int good;
int c[MaxN][MaxN];
int state[MaxN][MaxN];
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (c[i][1] == c[i][2] && c[i][2] != c[i][3] && state[i][1] == 1 && state[i][2] == 1 && state[i][3] == 1)
        {
            return true;
        }
        if (c[i][3] == c[i][2] && c[i][2] != c[i][1] && state[i][1] == 1 && state[i][2] == 1 && state[i][3] == 1)
        {
            return true;
        }
        if (c[1][i] == c[2][i] && c[2][i] != c[3][i] && state[1][i] == 1 && state[2][i] == 1 && state[3][i] == 1)
        {
            return true;
        }
        if (c[3][i] == c[2][i] && c[2][i] != c[1][i] && state[1][i] == 1 && state[2][i] == 1 && state[3][i] == 1)
        {
            return true;
        }
    }
    if (c[1][1] == c[2][2] && c[2][2] != c[3][3] && state[1][1] == 1 && state[2][2] == 1 && state[3][3] == 1)
    {
        return true;
    }
    if (c[3][3] == c[2][2] && c[2][2] != c[1][1] && state[1][1] == 1 && state[2][2] == 1 && state[3][3] == 1)
    {
        return true;
    }
    if (c[1][3] == c[2][2] && c[3][1] != c[2][2] && state[1][3] == 1 && state[2][2] == 1 && state[3][1] == 1)
    {
        return true;
    }
    if (c[3][1] == c[2][2] && c[2][2] != c[1][3] && state[1][3] == 1 && state[2][2] == 1 && state[3][1] == 1)
    {
        return true;
    }
    return false;
}
void dfs(int x, int y)
{
    if (x == 4)
    {
        bad += check() ? 1 : 0;
        good += check() ? 0 : 1;
    }
    else
    {
        for (int i = 1; i <= n * n; i++)
        {
            state[x][y] = i;
            if (y == n)
            {
                dfs(x + 1, 1);
            }
            else
            {
                dfs(x, y + 1);
            }
        }
        for (int i = 1; i <= n * n; i++)
        {
            if (y == n)
            {
                dfs(x + 1, 1);
            }
            else
            {
                dfs(x, y + 1);
            }
        }
    }
}
int main()
{
    n = 3;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    dfs(1, 1);
    printf("%.8lf", (double)(bad) / (double)(good + bad));
    return 0;
}