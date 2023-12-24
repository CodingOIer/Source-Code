#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int main()
{
    scanf("%d", &n);
    if (1 <= n)
    {
        ans += min(9, n - 1 + 1);
    }
    if (100 <= n)
    {
        ans += min(900, n - 100 + 1);
    }
    if (10000 <= n)
    {
        ans += min(90000, n - 10000 + 1);
    }
    printf("%d\n", ans);
    return 0;
}