#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
bool fg[128];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (n % 2 == 1)
    {
        printf("No\n");
        return 0;
    }
    bool f = true;
    for (int i = 2; i <= n; i += 2)
    {
        f &= s[i] == s[i - 1];
        f &= !fg[int(s[i])];
        fg[int(s[i])] = true;
    }
    printf("%s\n", f ? "Yes" : "No");
    return 0;
}
