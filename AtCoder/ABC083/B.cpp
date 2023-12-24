#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int a, b;
int Sum(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else
    {
        return x % 10 + Sum(x / 10);
    }
}
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
    {
        if (a <= Sum(i) && Sum(i) <= b)
        {
            ans += i;
        }
    }
    printf("%d\n", ans);
    return 0;
}