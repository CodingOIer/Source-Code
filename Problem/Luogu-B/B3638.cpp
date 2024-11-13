#include <cstdio>
int r, b, c, d, e, sum, k;
int main()
{
    scanf("%d%d%d%d%d", &r, &b, &c, &d, &e);
    if (r > b)
    {
        k = 1;
    }
    else
    {
        k = 0;
    }
    if (c + d > e + e)
    {
        sum = r * c + b * d;
    }
    else
    {
        if (k == 1)
        {
            sum = b * 2 * e + (r - b) * c;
        }
        else
        {
            sum = r * 2 * e + (b - r) * d;
        }
    }
    printf("%d", sum);
    return 0;
}