#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
int main()
{
    scanf("%d", &n);
    int a, b;
    a = b = -0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        a = std::max(a, x);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        b = std::max(b, x);
    }
    printf("%d\n", a + b);
    return 0;
}