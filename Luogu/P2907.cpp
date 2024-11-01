#include <cstdio>
int n, k;
int solve(int n, int k)
{
    if ((n - k) % 2 == 0 && n > k)
    {
        return solve((n - k) / 2 + k, k) + solve((n - k) / 2, k);
    }
    else
    {
        return 1;
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    printf("%d\n", solve(n, k));
    return 0;
}