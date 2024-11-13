#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n, k;
char s[MaxN];
int main()
{
    scanf("%d", &k);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (n <= k)
    {
        printf("%s\n", s + 1);
    }
    else
    {
        s[k + 1] = '\0';
        printf("%s...\n", s + 1);
    }
    return 0;
}