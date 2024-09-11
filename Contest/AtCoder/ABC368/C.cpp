#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    long long t = 0;
    for (int i = 1; i <= n; i++)
    {
        long long g = p[i] / 5;
        t += 3 * g;
        p[i] -= 5 * g;
        for (; p[i] > 0;)
        {
            t++;
            if (t % 3 == 0)
            {
                p[i] -= 3;
            }
            else
            {
                p[i]--;
            }
        }
    }
    printf("%lld\n", t);
    return 0;
}