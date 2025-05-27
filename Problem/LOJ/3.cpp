#include <cstdio>
constexpr int MaxM = 1e3 + 5;
int n;
char s[MaxM];
int main()
{
    freopen("copycat.in", "r", stdin);
    freopen("copycat.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        printf("%s\n", s);
    }
    return 0;
}