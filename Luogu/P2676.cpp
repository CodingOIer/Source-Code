#include <algorithm>
#include <cstdio>
#include <functional>
constexpr int MaxN = 2e5 + 5;
int n, b;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n, std::greater<>());
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += p[i];
        if (sum >= b)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}