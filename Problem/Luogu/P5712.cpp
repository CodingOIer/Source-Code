#include <cstdio>
int x;
int main()
{
    scanf("%d", &x);
    if (x <= 1)
    {
        printf("Today, I ate %d apple.\n", x);
    }
    else
    {
        printf("Today, I ate %d apples.\n", x);
    }
    return 0;
}