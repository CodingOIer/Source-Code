#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    printf("%d\n", min(n * a, b));
    return 0;
}