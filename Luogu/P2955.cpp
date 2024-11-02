#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf(" ");
        scanf("%s", s);
        printf("%s\n", (s[strlen(s) - 1] ^ 48) % 2 == 0 ? "even" : "odd");
    }
    return 0;
}