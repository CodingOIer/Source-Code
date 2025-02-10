#include <cstdio>
int a, b, c;
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    printf("%s\n", a * b == c || a * c == b || b * c == a ? "Yes" : "No");
    return 0;
}
