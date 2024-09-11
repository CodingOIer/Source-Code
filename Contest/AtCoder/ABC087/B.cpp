#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int x;
int ans;
int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &x);
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            for (int k = 0; k <= c; k++)
            {
                if (500 * i + 100 * j + 50 * k == x)
                {
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}