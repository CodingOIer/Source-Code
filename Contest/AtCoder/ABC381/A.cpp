#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    if (n % 2 == 0)
    {
        printf("No\n");
        return 0;
    }
    bool f = true;
    for (int i = 1; i <= n / 2; i++)
    {
        f &= s[i] == '1';
    }
    f &= s[n / 2 + 1] == '/';
    for (int i = n - (n / 2) + 1; i <= n; i++)
    {
        f &= s[i] == '2';
    }
    printf("%s\n", f ? "Yes" : "No");
    return 0;
}
