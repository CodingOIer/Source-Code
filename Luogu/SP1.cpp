#include <cstdio>
int main()
{
    int x;
    for (; scanf("%d", &x) == 1 && x != 42;)
    {
        printf("%d\n", x);
    }
    return 0;
}