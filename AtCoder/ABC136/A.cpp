#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", max((b + c) - a, 0));
    return 0;
}