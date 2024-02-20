#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e3 + 5;
const int m = 1e7 + 5;
int n, m;
int l, r;
int ans;
bool flag[MaxN], p[m];
int main()
{
    flag[0] = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &l, &r);
        for (int j = l; j <= r; j++)
        {
            p[j] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (flag[p[i]] == 0)
        {
            flag[p[i]] = 1;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}