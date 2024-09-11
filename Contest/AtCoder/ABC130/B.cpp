#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e4 + 5;
int n, x;
int sum;
int ans;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &x);
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        sum += p[i];
        if (sum <= x)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}