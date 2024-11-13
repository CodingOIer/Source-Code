#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
const int MaxM = 4e4 + 5;
int t;
bool f[MaxM];
long long x, y;
std::vector<int> prime;
std::vector<std::pair<int, int>> v;
void init(int limit = 4e4)
{
    for (int i = 2; i <= limit; i++)
    {
        if (f[i])
        {
            continue;
        }
        prime.push_back(i);
        for (int j = i * 2; j <= limit; j += i)
        {
            f[j] = true;
        }
    }
}
void solve()
{
    v.clear();
    scanf("%lld%lld", &x, &y);
    if (x % y != 0)
    {
        printf("%lld\n", x);
        return;
    }
    for (auto k : prime)
    {
        int cnt = 0;
        for (; y % k == 0;)
        {
            cnt++;
            y /= k;
        }
        if (cnt != 0)
        {
            v.push_back({k, cnt});
        }
    }
    if (y != 1)
    {
        v.push_back({y, 1});
    }
    long long answer = 0;
    for (auto [k, cnt] : v)
    {
        long long a = x;
        for (; a % k == 0;)
        {
            a /= k;
        }
        for (int i = 1; i <= cnt - 1; i++)
        {
            a *= k;
        }
        answer = std::max(answer, a);
    }
    printf("%lld\n", answer);
}
int main()
{
    init();
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}