#include <cstdio>
#include <numeric>
constexpr int MaxN = 1e6 + 5;
int n;
int p[MaxN];
int b[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        b[p[i]]++;
    }
    int answer = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        answer += b[i];
        if (b[i] != 0)
        {
            continue;
        }
        int g = -1;
        for (int j = 2; i * j <= 1'000'000; j++)
        {
            if (b[i * j] != 0)
            {
                g = g == -1 ? i * j : std::gcd(g, i * j);
            }
        }
        if (g == i)
        {
            answer++;
        }
    }
    printf("%d\n", answer - n);
    return 0;
}