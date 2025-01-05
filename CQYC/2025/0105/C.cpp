#include <cstdio>
#include <map>
#include <random>
#include <vector>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 5e2 + 5;
int n;
long long Mod;
unsigned long long base[MaxN];
std::map<unsigned long long, bool> vis;
std::map<unsigned long long, bool> map;
std::vector<std::vector<long long>> v;
unsigned long long fsp(unsigned long long x, long long y)
{
    unsigned long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res = res * x % Mod;
        }
        x = x * x % Mod;
        y >>= 1;
    }
    return res;
}
unsigned long long getHash(const std::vector<long long> &v)
{
    int cnt = 0;
    unsigned long long res = 0;
    for (const auto &val : v)
    {
        res += fsp(val + 975432499, base[++cnt]);
    }
    return res;
}
void dfs(const std::vector<std::vector<long long>> &v)
{
    if (v.size() == 1)
    {
        map[getHash(v[0])] = true;
        return;
    }
    unsigned long long allHash = 0;
    for (int i = 0; i < int(v.size()); i++)
    {
        allHash += getHash(v[i]);
    }
    if (vis[allHash])
    {
        return;
    }
    vis[allHash] = true;
    for (int i = 0; i < int(v.size()); i++)
    {
        for (int j = i + 1; j < int(v.size()); j++)
        {
            std::vector<std::vector<long long>> cp;
            for (int k = 0; k < int(v.size()); k++)
            {
                if (k != i && k != j)
                {
                    cp.push_back(v[k]);
                }
            }
            std::vector<long long> temp;
            for (int k = 0; k < n; k++)
            {
                temp.push_back({v[j][k] + v[j][k] - v[i][k]});
            }
            cp.push_back(temp);
            dfs(cp);
            cp.pop_back();
            temp.clear();
            for (int k = 0; k < n; k++)
            {
                temp.push_back({v[i][k] + v[i][k] - v[j][k]});
            }
            cp.push_back(temp);
            dfs(cp);
        }
    }
}
int main()
{
    scanf("%d%lld", &n, &Mod);
    for (int i = 1; i <= n; i++)
    {
        base[i] = rnd();
        std::vector<long long> temp;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                temp.push_back(1);
            }
            else
            {
                temp.push_back(0);
            }
        }
        v.push_back(temp);
    }
    dfs(v);
    printf("%zu\n", map.size());
    return 0;
}
