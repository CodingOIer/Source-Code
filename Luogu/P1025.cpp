#include <cstdio>
int n, k;
int dfs(int n, int k)
{
    if (n == 0 || k == 0)
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
    printf("%d", dfs(n, k));
    return 0;
}