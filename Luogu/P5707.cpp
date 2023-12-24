#include <cstdio>
int x, y;
int h, m;
int main()
{
    scanf("%d%d", &x, &y);
    h = 7;
    m = 50;
    m -= x / y + (x % y == 0 ? 0 : 1);
    for (; m < 0;)
    {
        h--;
        m += 60;
    }
    printf("%02d:%02d\n", h >= 0 ? h : 24 + h, m);
    return 0;
}