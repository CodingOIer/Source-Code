#include <cstdio>
int h, w;
inline bool check(int x, int y)
{
    if ((0 <= (x - x % 10 + y / 10) && (x - x % 10 + y / 10) <= 23) &&
        (0 <= (y - y / 10 * 10 + x % 10 * 10) && (y - y / 10 * 10 + x % 10 * 10) <= 59))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    scanf("%d%d", &h, &w);
    for (;;)
    {
        if (check(h, w))
        {
            printf("%d %d\n", h, w);
            break;
        }
        w++;
        if (w == 60)
        {
            w = 0;
            h++;
        }
        if (h == 24)
        {
            h = 0;
        }
    }
    return 0;
}