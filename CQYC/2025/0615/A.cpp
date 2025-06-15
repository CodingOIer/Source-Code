#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e6 + 5;
constexpr int Mod = 1e9 + 7;
int n, m;
int deg[MaxN];
int toc[MaxN];
long long answer;
std::vector<int> v;
long long f(long long x, long long y)
{
    return (x ^ y) * (x | y) % Mod * (x & y) % Mod;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        toc[deg[i]]++;
        v.push_back(deg[i]);
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (const auto &x : v)
    {
        for (const auto &y : v)
        {
            answer += toc[x] * toc[y] % Mod * f(x, y) % Mod;
            answer %= Mod;
        }
    }
    printf("%lld\n", answer * 0x1dcd6504 % Mod);
    return 0;
}
