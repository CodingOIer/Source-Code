#include <algorithm>
#include <cstdio>
int h, w;
int main()
{
    long long sum = 0;
    long long c = 0x7f7f7f7f7f7f7f7f;
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h * w; i++)
    {
        long long x;
        scanf("%lld", &x);
        c = std::min(c, x);
        sum += x;
    }
    printf("%lld\n", sum - c * h * w);
    return 0;
}