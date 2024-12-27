#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
constexpr int MaxN = 1e5 + 5;
constexpr long long Mod = 1'000'000'007;
int m;
int c[MaxN];
int d[MaxN];
long long n, value;
std::vector<int> v;
std::map<int, int> p;
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res = res * x % Mod;
        }
        y >>= 1;
        x = x * x % Mod;
    }
    return res;
}
void solve()
{
    v.clear();
    p.clear();
    scanf("%lld%d%lld", &n, &m, &value);
    bool suc = true;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &c[i], &d[i]);
        if (p.count(c[i]) && p[c[i]] != d[i])
        {
            suc = false;
        }
        p[c[i]] = d[i];
    }
    if (!suc)
    {
        printf("0\n");
        return;
    }
    for (const auto &[key, val] : p)
    {
        v.push_back(key);
    }
    std::sort(v.begin(), v.end());
    int last = -1;
    long long answer = 1;
    for (const auto &val : v)
    {
        if (last == -1)
        {
            answer *= fsp(value, 2 * (val - 1));
        }
        else
        {
            answer *= (fsp(value, 2 * (val - last)) - fsp(value, (val - last - 1)) * (value - 1) % Mod + Mod);
        }
        answer %= Mod;
        last = val;
    }
    answer *= fsp(value, 2 * (n - last));
    answer %= Mod;
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
