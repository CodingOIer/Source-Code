#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2e5 + 5;
int n;
int x;
int f[MaxN];
int l[MaxN];
char s[MaxN];
stack<int> stk;
int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else if (s[i] == ')' && !stk.empty())
        {
            x = stk.top();
            stk.pop();
            f[x] = 1;
            f[i] = 2;
        }
    }
    x = 0;
    for (int i = 0; i < n; i++)
    {
        if (x > 0)
        {
            l[i] = 1;
        }
        if (f[i] == 1)
        {
            x++;
        }
        else if (f[i] == 2)
        {
            x--;
        }
        if (x > 0)
        {
            l[i] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!l[i])
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}