#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n;
int maxDepth[MaxN];
std::vector<int> g[MaxN];
int dfsUpstream(int u, int f)
{
    int res = 0;
    for (auto v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        res = std::max(res, dfsUpstream(v, u));
    }
    maxDepth[u] = res;
    return res + 1;
}
void dfsDownstream(int u, int f, int val)
{
    maxDepth[u] = std::max(maxDepth[u], val);
    std::multiset<int> set;
    for (auto v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        set.insert(maxDepth[v] + 1);
    }
    for (auto v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        int backup = maxDepth[v] + 1;
        set.erase(set.find(backup));
        dfsDownstream(v, u, std::max(val, set.empty() ? 0 : *set.rbegin()) + 1);
        set.insert(backup);
    }
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsUpstream(1, 0);
    dfsDownstream(1, 0, 0);
    std::sort(maxDepth + 1, maxDepth + 1 + n);
    int it = 1;
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", std::min(res, n));
        for (; maxDepth[it] == i;)
        {
            it++;
            res++;
        }
    }
    printf("\n");
    return 0;
}