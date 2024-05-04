#include <cstdio>
int x, y;
int main()
{
    scanf("%d:%d", &x, &y);
    if (x >= 6)
    {
        printf("%02d:%02d\n", x, y);
    }
    else
    {
        printf("%02d:%02d\n", 24 + x, y);
    }
    return 0;
}