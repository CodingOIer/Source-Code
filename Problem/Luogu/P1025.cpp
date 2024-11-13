#include <cstdio>
int n, k;
int dfs(int n, int k)
{
    if (k == 0)
    {
        return 0;
    }
    else if (n == 0 || k == 1)
    {
        return 1;
    }
    else
    {
        if (n >= k)
        {
            return dfs(n - k, k) + dfs(n, k - 1);
        }
        else
        {
            return dfs(n, k - 1);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    printf("%d", dfs(n, k) / 2);
    return 0;
}