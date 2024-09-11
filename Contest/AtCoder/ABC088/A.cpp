#include <bits/stdc++.h>
using namespace std;
int n, a;
int main()
{
    scanf("%d%d", &n, &a);
    printf("%s\n", (n % 500 <= a) ? "Yes" : "No");
    return 0;
}