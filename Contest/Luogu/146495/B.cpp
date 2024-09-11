#include <algorithm>
#include <cstdio>
int t;
long long abs(long long x)
{
    return x > 0 ? x : -x;
}
long long dis(long long x1, long long y1, long long x2, long long y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        long long xa, ya, xb, yb, xc, yc, xd, yd;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);
        long long answer = 0;
        if (xc < xa)
        {
            answer++;
        }
        else if (xa <= xc && xc <= xb)
        {
        }
        else if (xc > xb)
        {
            answer++;
        }
        if (ya < yc)
        {
            answer++;
        }
        else if (yc <= ya && ya <= yd)
        {
        }
        else if (ya > yd)
        {
            answer++;
        }
        printf("%lld\n", answer);
    }
    return 0;
}