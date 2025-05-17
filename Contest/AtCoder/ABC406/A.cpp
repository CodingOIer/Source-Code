#include <cstdio>
int a, b, c, d;
int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%s\n", c < a || (c == a && d < b) ? "Yes" : "No");
    return 0;
}