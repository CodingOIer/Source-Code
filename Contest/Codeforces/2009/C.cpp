#include <algorithm>
#include <cstdio>
long long x, y, k;
inline void solve()
{
    scanf("%lld%lld%lld", &x, &y, &k);
    long long a, b;
    a = (x + k - 1) / k;
    b = (y + k - 1) / k;
    if (a > b)
    {
        b = std::max(b, a - 1);
    }
    else if (a < b)
    {
        a = b;
    }
    printf("%lld\n", a + b);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
