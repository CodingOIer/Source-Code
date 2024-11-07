#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    printf("%c", s[n / 2 + 1]);
    return 0;
}