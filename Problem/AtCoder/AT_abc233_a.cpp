#include <cstdio>
int x, y;
int main()
{
    scanf("%d%d", &x, &y);
    for (int i = 0;; i++)
    {
        if (x >= y)
        {
            printf("%d\n", i);
            break;
        }
        x += 10;
    }
    return 0;
}