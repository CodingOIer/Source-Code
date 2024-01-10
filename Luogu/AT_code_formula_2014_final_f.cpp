#include <cstdio>
int main()
{
    int x, y;
    x = 0;
    y = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (x + i > 1500)
        {
            x = 0;
            y += 2 * (i - 1);
        }
        printf("%d %d\n", x + i, y + i);
        x += 2 * i;
    }
    return 0;
}