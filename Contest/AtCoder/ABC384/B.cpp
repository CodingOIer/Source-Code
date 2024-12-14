#include <cstdio>
int n, r;
int main()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 1 && 1600 <= r && r <= 2799)
        {
            r += y;
        }
        if (x == 2 && 1200 <= r && r <= 2399)
        {
            r += y;
        }
    }
    printf("%d", r);
    return 0;
}
