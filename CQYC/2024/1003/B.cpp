#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e2 + 5;
int n;
std::vector<int> v[MaxN];
std::vector<int> g[MaxN];
int main()
{
    freopen(".in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        v[x].push_back(i);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < int(v[i].size()) - 1; j++)
        {
            g[v[i][j]].push_back(v[i][j + 1]);
            g[v[i][j + 1]].push_back(v[i][j]);
        }
        if (v[i].size() >= 2)
        {
            g[*v[i].begin()].push_back(*v[i].rbegin());
            g[*v[i].rbegin()].push_back(*v[i].begin());
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        std::sort(g[i].begin(), g[i].end());
        g[i].erase(std::unique(g[i].begin(), g[i].end()), g[i].end());
        if (int(g[i].size()) <= 1)
        {
            answer++;
        }
    }
    printf("%d\n", (answer + 1) / 2);
    return 0;
}