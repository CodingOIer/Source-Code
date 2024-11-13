#include <algorithm>
#include <cstdio>
int a, b, c;
int x, y, z;
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    x = std::min({a, b, c});
    z = std::max({a, b, c});
    y = a + b + c - x - z;
    if (x + y <= z)
    {
        printf("Not triangle\n");
    }
    else
    {
        if (x * x + y * y == z * z)
        {
            printf("Right triangle\n");
        }
        if (x * x + y * y > z * z)
        {
            printf("Acute triangle\n");
        }
        if (x * x + y * y < z * z)
        {
            printf("Obtuse triangle\n");
        }
        if (x == y || y == z)
        {
            printf("Isosceles triangle\n");
        }
        if (x == y && y == z)
        {
            printf("Equilateral triangle\n");
        }
    }
    return 0;
}