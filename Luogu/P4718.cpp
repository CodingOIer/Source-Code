#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e5 + 5;
int t;
char cmd[MaxN];
char result[MaxN];
long long x;
void solve()
{
    scanf("%lld", &x);
    sprintf(cmd, "factor %lld", x);
    FILE *p = popen(cmd, "r");
    fgets(result, sizeof(result), p);
    long long r = 0;
    long long k = 1;
    int l = strlen(result);
    for (int i = l - 2;; i--)
    {
        if (result[i] == ' ')
        {
            break;
        }
        r += k * (result[i] - '0');
        k *= 10;
    }
    if (r == x)
    {
        printf("Prime\n");
    }
    else
    {
        printf("%lld\n", r);
    }
    pclose(p);
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