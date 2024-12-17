#include <cassert>
#include <cstdio>
#include <map>
#include <random>
#include <tuple>
#include <vector>
std::mt19937_64 rnd(std::random_device{}());
constexpr int MaxN = 1e2 + 5;
int n;
int p[MaxN];
unsigned long long baseSha[MaxN];
std::vector<int> v;
std::map<std::tuple<unsigned long long, char>, char> mem;
unsigned long long sha(const std::vector<int> &v)
{
    unsigned long long res = 0;
    for (int i = 0; i < int(v.size()); i++)
    {
        res += baseSha[v[i]];
    }
    return res;
}
char calc(const std::vector<int> &v, char op)
{
    auto hash = sha(v);
    if (mem.count({hash, op}))
    {
        return mem[{hash, op}];
    }
    auto c = v;
    if (op == 'A')
    {
        for (int i = 0; i < int(v.size()); i++)
        {
            for (int j = 1; j <= v[i]; j++)
            {
                c[i] -= j;
                char ch = calc(c, 'B');
                if (ch == 'A')
                {
                    c[i] += j;
                    mem[{hash, op}] = op;
                    return op;
                }
                c[i] += j;
            }
        }
        mem[{hash, op}] = 'B';
        return 'B';
    }
    else
    {
        for (int i = 0; i < int(v.size()); i++)
        {
            for (int k = 0; k < int(v.size()); k++)
            {
                for (int j = 1; j <= v[i]; j++)
                {
                    for (int l = 1; l <= v[k]; l++)
                    {
                        c[i] -= j;
                        c[k] -= l;
                        if (c[i] < 0 || c[k] < 0)
                        {
                            c[i] += j;
                            c[k] += l;
                            continue;
                        }
                        char ch = calc(c, 'A');
                        if (ch == 'B')
                        {
                            c[i] += j;
                            c[k] += l;
                            mem[{hash, op}] = op;
                            return op;
                        }
                        c[i] += j;
                        c[k] += l;
                    }
                }
            }
        }
        mem[{hash, op}] = 'A';
        return 'A';
    }
}
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    v.clear();
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 1)
        {
            x++;
            continue;
        }
        if (p[i] % 2 == 0)
        {
            p[i] = 2;
        }
        else
        {
            p[i] = 3;
        }
        v.push_back(p[i]);
    }
    x %= 3;
    for (int i = 1; i <= x; i++)
    {
        v.push_back(1);
    }
    char ch = calc(v, 'A');
    if (ch == 'A')
    {
        printf("Win\n");
    }
    else
    {
        printf("Lose\n");
    }
}
int main()
{
    for (int i = 1; i <= 100; i++)
    {
        baseSha[i] = rnd();
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
