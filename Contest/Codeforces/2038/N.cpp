#include <cstdio>
char s[5];
inline void solve()
{
    scanf(" ");
    scanf("%s", s + 1);
    if (s[1] < s[3])
    {
        s[2] = '<';
    }
    else if (s[1] == s[3])
    {
        s[2] = '=';
    }
    else
    {
        s[2] = '>';
    }
    printf("%s\n", s + 1);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
