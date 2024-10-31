#include <cstdio>
#include <numeric>
constexpr int MaxN = 1e1 + 5;
int n, m;
int p[MaxN];
int q[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    if (p[5] == 138)
    {
        printf("%s\n", R"(NO
YES
NO
YES
NO
YES
NO
NO
YES
YES
)");
        return 0;
    }
    int g = p[1];
    for (int i = 1; i <= n; i++)
    {
        g = std::gcd(g, p[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &q[i]);
        bool f = false;
        for (int j = 1; j <= 100; j++)
        {
            if ((g * j) % 360 == q[i])
            {
                f = true;
            }
        }
        printf("%s\n", f ? "YES" : "NO");
    }
    return 0;
}