#include <cstdio>
constexpr int MaxN = 5e5 + 5;
int n, x;
int p[MaxN];
int t[MaxN];
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        t[p[i]]++;
    }
    constexpr int maxValue = 5e5 + 5;
    for (int i = 1; i <= maxValue; i++)
    {
        for (; t[i] >= i + 1;)
        {
            t[i] -= i + 1;
            t[i + 1]++;
        }
    }
    for (int i = 1; i <= maxValue; i++)
    {
        if (t[i] != 0)
        {
            if (i >= x)
            {
                printf("Yes\n");
                return 0;
            }
            else
            {
                printf("No\n");
                return 0;
            }
        }
    }
    return 0;
}
