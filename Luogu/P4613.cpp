#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
int p[MaxN];
int b[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    std::sort(p + 1, p + 1 + n);
    std::sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (p[i] > b[i])
        {
            printf("NE\n");
            return 0;
        }
    }
    printf("DA\n");
    return 0;
}