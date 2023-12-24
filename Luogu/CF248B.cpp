#include <bits/stdc++.h>
using namespace std;
int n;
int x[15] = {110, 50, 80, 170, 20, 200};
int main()
{
    scanf("%d", &n);
    if (n == 1 || n == 2)
    {
        printf("-1\n");
    }
    else if (n == 3)
    {
        printf("210\n");
    }
    else
    {
        printf("1");
        for (int i = 1; i <= n - 4; i++)
        {
            printf("0");
        }
        printf("%03d\n", x[(n - 3) % 6]);
    }
    return 0;
}