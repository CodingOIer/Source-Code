#include <cstdio>
int l, r;
void solve()
{
    scanf("%d%d", &l, &r);
    if (l == 1)
    {
        if (r == 1)
        {
            printf("1\n");
        }
        else
        {
            printf("%d\n", r - l);
        }
    }
    else
    {
        printf("%d\n", r - l);
    }
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
