#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
    scanf("%d%d", &a, &b);
    if ((a * b) % 2 == 0)
    {
        printf("Even\n");
    }
    else
    {
        printf("Odd\n");
    }
    return 0;
}