#include <cmath>
#include <cstdio>
#include <ctime>
#include <tuple>
double l, r;
double xa, ya, xb, yb, xc, yc;
double dis(double xx, double yx, double xy, double yy)
{
    return sqrt((xx - xy) * (xx - xy) + (yx - yy) * (yx - yy));
}
double get(double p)
{
    double xd, yd, xe, ye, xf, yf;
    xf = xa + (xb - xa) * p;
    yf = ya + (yb - ya) * p;
    xd = xb + (xc - xb) * p;
    yd = yb + (yc - yb) * p;
    xe = xc + (xa - xc) * p;
    ye = yc + (ya - yc) * p;
    double a, b, c;
    a = dis(xd, yd, xe, ye);
    b = dis(xd, yd, xf, yf);
    c = dis(xe, ye, xf, yf);
    double k = (a + b + c) / 2;
    return sqrt(k * (k - a) * (k - b) * (k - c));
}
std::tuple<double, double, double> calc(double p)
{
    double l, r;
    l = p * 0.999999;
    r = p * 1.000001;
    return {get(l), get(p), get(r)};
}
int main()
{
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &l, &r, &xa, &ya, &xb, &yb, &xc, &yc);
    double answer = 1e15;
    for (; l * 1.000000000001 <= r;)
    {
        double mid = (l + r) / 2;
        double a, b, c;
        std::tie(a, b, c) = calc(mid);
        if (a >= b && b <= c)
        {
            answer = b;
            break;
        }
        else if (a >= b && b >= c)
        {
            answer = c;
            l *= 1.000001;
        }
        else if (a <= b && b <= c)
        {
            answer = a;
            r *= 0.999999;
        }
    }
    printf("%.8lf\n", answer);
    return 0;
}