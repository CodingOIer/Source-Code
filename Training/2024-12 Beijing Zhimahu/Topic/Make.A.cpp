#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <utility>
constexpr int MaxN = 1e2 + 5;
int n, m;
int p[MaxN];
int f[MaxN];
int a[MaxN];
int b[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            m++;
            a[m] = i;
            b[m] = j;
        }
    }
    std::iota(f + 1, f + 1 + m, 1);
    for (;;)
    {
        std::iota(p + 1, p + 1 + n, 1);
        for (int i = 1; i <= m; i++)
        {
            std::swap(p[a[f[i]]], p[b[f[i]]]);
        }
        bool suc = true;
        for (int i = 1; i <= n; i++)
        {
            suc &= p[i] == i;
        }
        if (suc)
        {
            printf("YES\n");
            for (int i = 1; i <= m; i++)
            {
                printf("%d %d\n", a[i], b[i]);
            }
            return 0;
        }
        if (!std::next_permutation(f + 1, f + 1 + m))
        {
            break;
        }
    }
    printf("NO");
    return 0;
}
