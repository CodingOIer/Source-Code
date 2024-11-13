#include <algorithm>
#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    int a, b;
    a = 0x7f7f7f7f;
    b = -0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        a = std::min(a, x);
        b = std::max(b, x);
    }
    printf("%d\n", b - a);
    return 0;
}