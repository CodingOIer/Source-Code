#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    double x, y;
    x = y = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        x += k;
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        y += k;
    }
    printf("%.6lf\n", (x * 3 - y * 2) / (x - y));
    return 0;
}