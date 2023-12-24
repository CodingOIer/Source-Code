#include <cmath>
#include <cstdio>
const long long MaxN = 5e5 + 5;
long long go;
long long n, t;
long long w[MaxN];
long long x_0, y_0;
long long x_1, y_1;
long long x_2, y_2;
long long x_3, y_3;
long long answer_x;
long long answer_y;
long long move_x[] = {0, 1, 0, -1};
long long move_y[] = {1, 0, -1, 0};
int main()
{
    freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    scanf("%lld%lld", &n, &t);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &w[i]);
    }
    go = 0;
    for (long long i = 1; i <= n; i++)
    {
        x_0 += move_x[go] * w[i];
        y_0 += move_y[go] * w[i];
        go += w[i];
        go %= 4;
    }
    long long change = go;
    go = 1;
    for (long long i = 1; i <= n; i++)
    {
        x_1 += move_x[go] * w[i];
        y_1 += move_y[go] * w[i];
        go += w[i];
        go %= 4;
    }
    go = 2;
    for (long long i = 1; i <= n; i++)
    {
        x_2 += move_x[go] * w[i];
        y_2 += move_y[go] * w[i];
        go += w[i];
        go %= 4;
    }
    go = 3;
    for (long long i = 1; i <= n; i++)
    {
        x_3 += move_x[go] * w[i];
        y_3 += move_y[go] * w[i];
        go += w[i];
        go %= 4;
    }
    go = 0;
    for (long long i = 1; i <= t; i++)
    {
        if (go == 0)
        {
            answer_x += x_0;
            answer_y += y_0;
        }
        else if (go == 1)
        {
            answer_x += x_1;
            answer_y += y_1;
        }
        else if (go == 2)
        {
            answer_x += x_2;
            answer_y += y_2;
        }
        else if (go == 3)
        {
            answer_x += x_3;
            answer_y += y_3;
        }
        go += change;
        go %= 4;
    }
    printf("%lld\n", _abs64(answer_x) + _abs64(answer_y));
    return 0;
}