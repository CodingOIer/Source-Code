#include <bits/stdc++.h>
using namespace std;
int x, a, b;
int main()
{
    scanf("%d%d%d", &x, &a, &b);
    printf("%d\n", (x - a) % b);
    return 0;
}