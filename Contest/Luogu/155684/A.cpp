#include <cstdio>
constexpr int MaxN = 2e3 + 5;
int n, m;
char p[MaxN][MaxN];
bool check(int x, int y)
{
    if (y == 1 || x == n)
    {
        return true;
    }
    return (p[x][y] == p[x + 1][y - 1]) && check(x + 1, y - 1);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", p[i] + 1);
    }
    int answer = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!check(1, i))
        {
            printf("%d\n", answer);
            return 0;
        }
        answer++;
    }
    for (int i = 2; i <= n; i++)
    {

        if (!check(i, m))
        {
            printf("%d\n", answer);
            return 0;
        }
        answer++;
    }
    printf("%d\n", n + m - 1);
    return 0;
}