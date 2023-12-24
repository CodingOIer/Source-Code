#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2e5 + 5;
int n, k, t;
int a[MaxN], b[MaxN];
int main()
{
    freopen("rotate.in", "r", stdin);
    freopen("rotate.out", "w", stdout);
    scanf("%d%d%d", &n, &k, &t);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &a[i]);
    }
    a[k + 1] = n;
    for (int i = 1; i <= k; i++)
    {
        int sum = a[i + 1] - a[i];
        for (int j = 0; j < sum; j++)
        {
            b[(a[i] + j + int(ceil(1.0 * (t - j) / sum)) * sum) % n] = a[i] + j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}