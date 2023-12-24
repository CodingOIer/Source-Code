#include <bits/stdc++.h>
using namespace std;
int t;
int n, x;
int input;
int one, two;
void solve()
{
    one = 0;
    two = 0;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &input);
        if (input % 2 == 1)
        {
            one++;
        }
        else if (input % 2 == 0)
        {
            two++;
        }
    }
    if (x % 2 == 1)
    {
        if ()
    }
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}