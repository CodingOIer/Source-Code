#include <bits/stdc++.h>
using namespace std;
const int MaxN = 15;
const int D = 15;
int n, d;
int ans;
int sum;
int p[MaxN][D];
int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            sum = 0;
            for (int k = 1; k <= d; k++)
            {
                sum += abs(p[i][k] - p[j][k]) * abs(p[i][k] - p[j][k]);
            }
            if (sum == int(sqrt(double(sum))) * int(sqrt(double(sum))))
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}