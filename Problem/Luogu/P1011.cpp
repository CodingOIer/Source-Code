#include <cstdio>
constexpr int MaxN = 2e1 + 5;
int a, n, m, w;
int goIn[MaxN];
int goOut[MaxN];
int main()
{
    scanf("%d%d%d%d", &a, &n, &m, &w);
    goIn[1] = a;
    for (int in2 = 0;; in2++)
    {
        goIn[2] = in2;
        goOut[2] = in2;
        int x = 0;
        for (int i = 3; i <= n - 1; i++)
        {
            goIn[i] = goIn[i - 1] + goIn[i - 2];
            goOut[i] = goIn[i - 1];
        }
        for (int i = 1; i <= n - 1; i++)
        {
            x += goIn[i] - goOut[i];
        }
        if (x != m)
        {
            continue;
        }
        x = 0;
        for (int i = 1; i <= w; i++)
        {
            x += goIn[i] - goOut[i];
        }
        printf("%d\n", x);
        break;
    }
    return 0;
}
