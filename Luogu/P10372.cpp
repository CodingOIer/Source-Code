#include <cstdio>
int t;
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int a, b, c;
        scanf("%d+%d=%d", &a, &b, &c);
        printf("%s\n", a + b == c ? "Right!" : "Wrong!");
    }
    return 0;
}