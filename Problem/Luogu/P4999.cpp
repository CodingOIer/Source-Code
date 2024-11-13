#include <cstdio>
constexpr long long Mod = 1e9 + 7;
constexpr long long Sum2 = 2250000;
constexpr long long Sum3 = 999996857;
constexpr long long Sum4 = 955900007;
constexpr long long Step1 = 1e5;
constexpr long long Step2 = 1e5;
constexpr long long Step3 = 1e4;
constexpr long long Less1 = 99999;
constexpr long long Less2 = 99999;
constexpr long long Less3 = 9999;
int t;
long long l, r;
long long answer;
inline void add(long long x)
{
    answer += x;
    answer %= Mod;
}
inline void addAnswer(long long x, long long cnt = 1)
{
    for (; x != 0;)
    {
        add((x % 10) * cnt);
        x /= 10;
    }
}
inline void solve()
{
    answer = 0;
    scanf("%lld%lld", &l, &r);
    // Step 1: 1 ~ 10^5
    for (; l % Step1 != 0 && l <= r;)
    {
        addAnswer(l);
        l++;
    }
    for (; r % Step1 != Less1 && r >= l;)
    {
        addAnswer(r);
        r--;
    }
    if (l > r)
    {
        printf("%lld\n", answer);
        return;
    }
    l /= Step1;
    r /= Step1;
    // Step 2: 10^5 ~ 10^10
    for (; l % Step2 != 0 && l <= r;)
    {
        add(Sum2);
        addAnswer(l, Step1);
        l++;
    }
    for (; r % Step2 != Less2 && r >= l;)
    {
        add(Sum2);
        addAnswer(r, Step1);
        r--;
    }
    if (l > r)
    {
        printf("%lld\n", answer);
        return;
    }
    l /= Step2;
    r /= Step2;
    // Step 3: 10^10 ~ 10^14
    for (; l % Step3 != 0 && l <= r;)
    {
        add(Sum3);
        addAnswer(l, Step1 * Step2);
        l++;
    }
    for (; r % Step3 != Less3 && r >= l;)
    {
        add(Sum3);
        addAnswer(r, Step1 * Step2);
        r--;
    }
    if (l > r)
    {
        printf("%lld\n", answer);
        return;
    }
    l /= Step3;
    r /= Step3;
    for (; l <= r;)
    {
        add(Sum4);
        addAnswer(l, Step1 * Step2 * Step3);
        l++;
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