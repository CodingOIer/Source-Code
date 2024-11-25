#include <cmath>
#include <cstdio>
long long n;
inline void solve()
{
    scanf("%lld", &n);
    long long l, r;
    l = 1;
    r = 2e9;
    long long re = -1;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        if (mid * mid >= n)
        {
            r = mid - 1;
            re = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    long long answer = 2 * re;
    if (n % 2 == 1 || re * re == n || re * re - re < n)
    {
        answer++;
    }
    printf("%lld\n", answer);
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
