#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define debug printf("Debug\n")
typedef long long ll;
int t;
int n, m;
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        if (i % 2 == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    for (int i = 2; i <= n - 2; i++)
    {
        if (i % 2 == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        for (int j = 1; j <= m - 2; j++)
        {
            printf("0");
        }
        if (i % 2 == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        printf("\n");
    }
    for (int j = 1; j <= m; j++)
    {
        printf("0");
    }
    printf("\n");
    for (int i = 1; i <= m; i++)
    {
        if (i % 2 == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    printf("\n");
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}