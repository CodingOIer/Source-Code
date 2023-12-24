#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 5;
int x;
char s[MaxN];
int main()
{
    scanf("%s", s);
    scanf("%d", &x);
    printf("%c\n", s[x - 1]);
    return 0;
}