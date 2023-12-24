#include <algorithm>
#include <cstdio>
const int MaxN = 2e5 + 5;
int n, m;
unsigned long long p[MaxN];
unsigned long long answer;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%llu", &p[i]);
    }
    std::sort(p + 1, p + 1 + n, [](int x, int y) { return x > y; });
    int need = 0;
    for (;;)
    {
        need++;
        if (2 * need + (m - need) >= n)
        {
            break;
        }
    }
    for (int i = 1; i <= m - need; i++)
    {
        answer += p[i] * p[i];
    }
    if (n != 2 * need + (m - need))
    {
        answer += p[m - need + 1] * p[m - need + 1];
        for (int i = m - need + 2, j = n; i < j; i++, j--)
        {
            answer += (p[i] + p[j]) * (p[i] + p[j]);
        }
    }
    else
    {
        for (int i = m - need + 1, j = n; i < j; i++, j--)
        {
            answer += (p[i] + p[j]) * (p[i] + p[j]);
        }
    }
    printf("%llu\n", answer);
    return 0;
}