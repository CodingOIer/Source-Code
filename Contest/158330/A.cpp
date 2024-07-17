#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    scanf("%d", &n);
    printf("%c%d\n", s[1], n);
    return 0;
}