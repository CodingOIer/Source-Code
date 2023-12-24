#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a + b > c + d)
    {
        printf("Left\n");
    }
    else if (a + b == c + d)
    {
        printf("Balanced\n");
    }
    else if (a + b < c + d)
    {
        printf("Right\n");
    }
    return 0;
}