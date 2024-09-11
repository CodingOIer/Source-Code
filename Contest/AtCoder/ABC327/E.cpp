#include <algorithm>
#include <cmath>
#include <cstdio>
const int MaxN = 5e3 + 5;
int n;
double answer;
double up, down, k;
double p[MaxN];
double calc(double x, double y, double k)
{
    return x / y - 1200.0 / sqrt(k);
}
int getMaxValue(int l, int r)
{
    int cur = l;
    for (int i = l; i <= r; i++)
    {
        if (p[i] >= p[cur])
        {
            cur = i;
        }
    }
    return cur;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &p[i]);
    }
    answer = -1200.0;
    int now = n;
    for (;;)
    {
        if (now < 1)
        {
            break;
        }
        int cur = getMaxValue(1, now);
        up += p[cur] * pow(0.9, k);
        down += pow(0.9, k);
        k++;
        answer = std::max(answer, calc(up, down, k));
        now = cur - 1;
    }
    printf("%.6lf\n", answer);
    return 0;
}