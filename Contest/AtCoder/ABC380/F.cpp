#include <cstdio>
#include <map>
#include <random>
#include <set>
#include <tuple>
#include <vector>
std::mt19937_64 rnd(std::random_device{}());
int n, m, l;
std::multiset<int> a;
std::multiset<int> b;
std::multiset<int> c;
std::map<int, unsigned long long> base;
std::map<std::tuple<unsigned long long, unsigned long long, unsigned long long>, bool> map;
unsigned long long hash(std::multiset<int> &s)
{
    unsigned long long r = 0;
    for (const auto &val : s)
    {
        r += base[val];
    }
    return r;
}
bool win(std::multiset<int> f, std::multiset<int> s, std::multiset<int> d)
{
    if (f.empty())
    {
        return false;
    }
    if (map.count({hash(f), hash(s), hash(d)}))
    {
        return map[{hash(f), hash(s), hash(d)}];
    }
    for (auto val : f)
    {
        auto it = d.lower_bound(val);
        std::vector<int> can;
        for (; it != d.begin();)
        {
            it--;
            can.push_back(*it);
        }
        auto a = f;
        auto b = s;
        auto c = d;
        a.erase(a.find(val));
        c.insert(val);
        if (!win(b, a, c))
        {
            map[{hash(f), hash(s), hash(d)}] = true;
            return true;
        }
        for (auto have : can)
        {
            auto a = f;
            auto b = s;
            auto c = d;
            a.insert(have);
            c.insert(val);
            a.erase(a.find(val));
            c.erase(c.find(have));
            if (!win(b, a, c))
            {
                map[{hash(f), hash(s), hash(d)}] = true;
                return true;
            }
        }
    }
    map[{hash(f), hash(s), hash(d)}] = false;
    return false;
}
int main()
{
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        base[x] = rnd();
        a.insert(x);
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        base[x] = rnd();
        b.insert(x);
    }
    for (int i = 1; i <= l; i++)
    {
        int x;
        scanf("%d", &x);
        base[x] = rnd();
        c.insert(x);
    }
    printf("%s\n", win(a, b, c) ? "Takahashi" : "Aoki");
    return 0;
}
