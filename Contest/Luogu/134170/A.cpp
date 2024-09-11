#include <algorithm>
#include <cstdio>
int n;
long long max_x, min_x;
long long max_y, min_y;
int main()
{
    scanf("%d", &n);
    min_x = 0x3f3f3f3f3f3f3f3f;
    min_y = 0x3f3f3f3f3f3f3f3f;
    max_x = -0x3f3f3f3f3f3f3f3f;
    max_y = -0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        long long x1, x2, y1, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        min_x = std::min({min_x, x1, x2});
        max_x = std::max({max_x, x1, x2});
        min_y = std::min({min_y, y1, y2});
        max_y = std::max({max_y, y1, y2});
    }
    printf("%lld\n", (max_x - min_x) * (max_y - min_y));
    return 0;
}