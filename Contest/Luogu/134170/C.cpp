#include <cstdio>
#include <cstring>
constexpr int MaxN = 5e5 + 5;
int t;
char s[MaxN];
long long x, y;
long long f(long long x)
{
    if (x == 0)
    {
        return 0;
    }
    return x + f(x / 10);
}
void solve()
{
    for (x = 0; x <= 1e6; x++)
    {
        if (f(x) == y)
        {
            printf("%lld\n", x);
            return;
        }
    }
    printf("-1\n");
}
void control()
{
    scanf("%s", s);
    if (strlen(s) <= 7)
    {
        sscanf(s, "%lld", &y);
        solve();
        /* }
        else
        { */
        int n = strlen(s);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int want = s[i] - '0';
            if (want < sum)
            {
                printf("-1\n");
                return;
            }
            sum = s[i] - '0';
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            int want = s[i] - '0';
            printf("%d", want - sum);
            sum = s[i] - '0';
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        control();
    }
    return 0;
}