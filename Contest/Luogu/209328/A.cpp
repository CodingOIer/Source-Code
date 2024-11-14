#include <algorithm>
#include <cstdio>
int q;
int main()
{
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        if (x == y)
        {
            printf("0\n");
        }
        else if (x % y == 0 || y % x == 0)
        {
            printf("%lld\n", std::max(x, y));
        }
        else
        {
            printf("%lld\n", x + y);
        }
    }
    return 0;
}
