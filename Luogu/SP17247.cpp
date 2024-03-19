#include <cstdio>
constexpr long long Once = 432000001;
int t;
long long x, y;
long long answer;
void add(long long x)
{
    for (; x != 0;)
    {
        answer += x % 10;
        x /= 10;
    }
}
void solve()
{
    answer = 0;
    scanf("%lld%lld", &x, &y);
    if (x == 0)
    {
        x++;
    }
    for (; x % 100000000 != 0 && x <= y;)
    {
        add(x);
        x++;
    }
    for (; y % 100000000 != 99999999 && y >= x;)
    {
        add(y);
        y--;
    }
    if (x > y)
    {
        printf("%lld\n", answer);
        return;
    }
    long long cnt = (y - x + 1) / 100000000;
    answer += cnt * Once;
    x /= 100000000;
    y /= 100000000;
    for (; x <= y;)
    {
        add(x);
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