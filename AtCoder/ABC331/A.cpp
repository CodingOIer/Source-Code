#include <cstdio>
int y, m, d;
int month, day;
int main()
{
    scanf("%d%d", &month, &day);
    scanf("%d%d%d", &y, &m, &d);
    if (m == month && d == day)
    {
        printf("%d %d %d\n", y + 1, 1, 1);
    }
    else if (d == day)
    {
        printf("%d %d %d\n", y, m + 1, 1);
    }
    else
    {
        printf("%d %d %d\n", y, m, d + 1);
    }
    return 0;
}