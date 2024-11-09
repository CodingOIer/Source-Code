#include <cstdio>
int a, b, c;
int main()
{
    char s[5];
    scanf("%s", s + 1);
    a = s[1] ^ 48;
    b = s[2] ^ 48;
    c = s[3] ^ 48;
    printf("%d%d%d ", b, c, a);
    printf("%d%d%d\n", c, a, b);
    return 0;
}