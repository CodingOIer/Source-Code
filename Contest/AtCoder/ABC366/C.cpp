#include <cmath>
#include <cstdio>
int ax, ay;
int bx, by;
int cx, cy;
int dx, dy;
bool gimp_transform_polygon_is_convex(double x1, double y1, double x2, double y2, double x3, double y3, double x4,
                                      double y4)
{
    double z1, z2, z3, z4;

    z1 = ((x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1));
    z2 = ((x4 - x1) * (y3 - y1) - (x3 - x1) * (y4 - y1));
    z3 = ((x4 - x2) * (y3 - y2) - (x3 - x2) * (y4 - y2));
    z4 = ((x3 - x2) * (y1 - y2) - (x1 - x2) * (y3 - y2));

    return (z1 * z2 > 0 && z3 * z4 > 0) || (z1 * z2 < 0 && z3 * z4 < 0);
}
int main()
{
    scanf("%d%d", &ax, &ay);
    scanf("%d%d", &bx, &by);
    scanf("%d%d", &cx, &cy);
    scanf("%d%d", &dx, &dy);
    if (gimp_transform_polygon_is_convex(ax, ay, bx, by, cx, cy, dx, dy))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}