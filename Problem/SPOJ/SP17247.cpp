#include <cstdio>
constexpr long long Sum1 = 2250000;
constexpr long long Sum2 = 450000000000;
int t;
long long x, y;
long long answer;
void add(long long x, long long cnt = 1)
{
    for (; x != 0;)
    {
        answer += (x % 10) * cnt;
        x /= 10;
    }
}
void solve()
{
    answer = 0;
    scanf("%lld%lld", &x, &y);
    for (; x % 100000 != 0 && x <= y;)
    {
        add(x);
        x++;
    }
    for (; y % 100000 != 99999 && y >= x;)
    {
        add(y);
        y--;
    }
    if (x > y)
    {
        printf("%lld\n", answer);
        return;
    }
    x /= 100000;
    y /= 100000;
    for (; x % 100000 != 0 && x <= y;)
    {
        add(x, 100000);
        answer += Sum1;
        x++;
    }
    for (; y % 100000 != 99999 && y >= x;)
    {
        add(y, 100000);
        answer += Sum1;
        y--;
    }
    if (x > y)
    {
        printf("%lld\n", answer);
        return;
    }
    x /= 100000;
    y /= 100000;
    for (; x <= y;)
    {
        add(x, 10000000000LL);
        answer += Sum2;
        x++;
    }
    printf("%lld\n", answer);
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}