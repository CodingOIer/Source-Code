#include <cstdio>
int a, b;
int main()
{
    scanf("%d%d", &a, &b);
    int x = 0;
    for (; a % 10 != b;)
    {
        x++;
        a++;
    }
    printf("%d\n", x);
    return 0;
}
