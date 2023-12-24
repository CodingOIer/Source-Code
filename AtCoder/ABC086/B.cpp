#include <bits/stdc++.h>
using namespace std;
int a, b;
int sum;
int main()
{
    scanf("%d%d", &a, &b);
    if (b < 10)
    {
        sum += a * 10 + b;
    }
    else if (b < 100)
    {
        sum += a * 100 + b;
    }
    else if (b < 1000)
    {
        sum += a * 1000 + b;
    }
    if (int(sqrt(sum)) * int(sqrt(sum)) == sum)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}