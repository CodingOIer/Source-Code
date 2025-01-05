// 100
#include <algorithm>
#include <cstdio>
#include <set>
#include <tuple>
#include <vector>
constexpr long long Mod = 1e9 + 7;
int n;
long long m;
std::set<int> set;
std::vector<std::tuple<long long, bool, int>> v;
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res *= x;
            res %= Mod;
        }
        y >>= 1;
        x *= x;
        x %= Mod;
    }
    return res;
}
int main()
{
    scanf("%d%*d", &n);
    for (int i = 1; i <= n; i++)
    {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        v.push_back({l - 1, false, i});
        v.push_back({r, true, i});
    }
    std::sort(v.begin(), v.end());
    long long all = 1ll * (n + 1) * n / 2;
    long long cannot = all;
    long long last = 0;
    long long answer = 0;
    set.insert(0);
    set.insert(n + 1);
    for (auto k : v)
    {
        int id;
        long long where;
        bool type;
        std::tie(where, type, id) = k;
        answer += 1ll * (where - last) % Mod * ((all - cannot) % Mod) % Mod;
        answer %= Mod;
        if (!type)
        {
            auto ptr = set.upper_bound(id);
            int a, b;
            b = *ptr;
            ptr--;
            a = *ptr;
            cannot -= 1ll * (b - a) * (b - a + 1) / 2;
            cannot += 1ll * (id - a) * (id - a + 1) / 2;
            cannot += 1ll * (b - id) * (b - id + 1) / 2;
            set.insert(id);
        }
        else if (type)
        {
            auto ptr = set.upper_bound(id);
            int a, b;
            b = *ptr;
            ptr--;
            ptr--;
            a = *ptr;
            cannot -= 1ll * (id - a) * (id - a + 1) / 2;
            cannot -= 1ll * (b - id) * (b - id + 1) / 2;
            cannot += 1ll * (b - a) * (b - a + 1) / 2;
            set.erase(id);
        }
        last = where;
    }
    printf("%lld\n", answer * fsp(all % Mod, Mod - 2) % Mod);
    return 0;
}