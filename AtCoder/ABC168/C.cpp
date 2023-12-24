#include <bits/stdc++.h>
using namespace std;
double a, b, h, w;
double l;
double x;
int main()
{
    scanf("%lf%lf%lf%lf", &a, &b, &h, &w);
    x = abs((h * 30 + w * 0.5) - (w * 6));
    // 求出夹角
    printf("%.10lf\n", sqrt(a * a + b * b - 2 * a * b * cos(x * M_PI / 180)));
    // 带入公式，注意保留10位小数
    return 0;
}