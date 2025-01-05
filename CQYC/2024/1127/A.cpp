// 100 =

#include <algorithm>
#include <cstdio>
long long a, b;
long long abs(long long x)
{
    return x < 0 ? -x : x;
}
void solve()
{
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", (a >= 0 && b >= 0) || (a <= 0 && b <= 0) ? 0 : std::min({abs(a + b), abs(a), abs(b)}));
}
int main()
{
    freopen("sub.in", "r", stdin);
    freopen("sub.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
