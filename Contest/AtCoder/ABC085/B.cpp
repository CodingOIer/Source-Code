#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e2 + 5;
int n;
int x;
int ans;
int b[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        b[x] = 1;
    }
    for (int i = 1; i <= 100; i++)
    {
        if (b[i])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}