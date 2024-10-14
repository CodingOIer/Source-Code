#include <cmath>
#include <cstdio>
int n;
inline double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main()
{
    scanf("%d", &n);
    int x, y;
    x = y = 0;
    double answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        answer += dis(x, y, a, b);
        x = a;
        y = b;
    }
    printf("%.12lf\n", answer + dis(x, y, 0, 0));
    return 0;
}