#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int n, m, k;
int p[MaxN];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &p[i]);
    }
    if (k == 0)
    {
        int current = 1;
        int now = 1;
        int answer = 0;
        for (; now <= n;)
        {
            for (; p[current] < now && current <= k;)
            {
                current++;
            }
            if (p[current] == now)
            {
                m++;
            }
            now += m;
            answer++;
        }
        printf("%d\n", answer);
    }
    else
    {
        int current = 1;
        int now = 0;
        int answer = 0;
        for (; now < n;)
        {
            for (; p[current] < now && current <= k;)
            {
                current++;
            }
            if (p[current] == now)
            {
                m++;
            }
            now += m;
            answer++;
        }
        printf("%d\n", answer);
    }
    return 0;
}