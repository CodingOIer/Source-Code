#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m - (n % m); i++)
    {
        printf("%d ", n / m);
    }
    for (int i = 1; i <= n % m; i++)
    {
        printf("%d ", n / m + 1);
    }
    printf("\n");
    return 0;
}