#include <cstdio>
#include <cstdlib>
const int MaxN = 7;
int n;
char r[MaxN];
char c[MaxN];
char active[MaxN][MaxN];
void check()
{
}
void dfs(int x)
{
    if (x == n + 1)
    {
        check();
    }
    else
    {
    }
}
int main()
{
    scanf("%d", &n);
    scanf("%s", r + 1);
    scanf("%s", c + 1);
    dfs(1);
    return 0;
}