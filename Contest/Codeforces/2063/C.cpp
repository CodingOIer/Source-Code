#include <algorithm>
#include <cstdio>
#include <set>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int in[MaxN];
std::vector<int> g[MaxN];
std::set<std::tuple<int, int>> set;
void solve()
{
    set.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        in[i] = 0;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        set.insert({in[i], i});
    }
    int answer = 0;
    for (int u = 1; u <= n; u++)
    {
        set.erase({in[u], u});
        for (const auto &v : g[u])
        {
            set.erase({in[v], v});
            in[v]--;
            set.insert({in[v], v});
        }
        int block = in[u];
        auto [_, v] = *set.rbegin();
        answer = std::max(answer, block + in[v] - 1);
        for (const auto &v : g[u])
        {
            set.erase({in[v], v});
            in[v]++;
            set.insert({in[v], v});
        }
        set.insert({in[u], u});
    }
    printf("%d\n", answer);
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
