#include <bits/stdc++.h>
using namespace std;
const int MaxN = 15;
int a, b;
char s[MaxN];
int main()
{
    scanf("%d%d", &a, &b);
    scanf("%s", s);
    if (s[a] - '0' >= 0 && s[a] - '0' <= 9)
    {
        printf("No\n");
    }
    else
    {
        for (int i = 0; i <= a + b; i++)
        {
            if (i == a)
            {
                continue;
            }
            if (!(s[i] - '0' >= 0 && s[i] - '0' <= 9))
            {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
    }
    return 0;
}