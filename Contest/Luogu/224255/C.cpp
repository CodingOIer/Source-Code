#include <cstdio>
int x, c, k;
int main()
{
    scanf("%d%d%d", &x, &c, &k);
    for (int i = 1; i <= k - 1; i++)
    {
        x = x * x + c;
        x %= 10000;
    }
    printf("%d\n", x);
    return 0;
}
