#include <cstdio>
#include <numeric>
#include <vector>
constexpr int MaxN = 4e5 + 5;
int block;
int n, m, k;
int ref[MaxN];
int kill[MaxN];
int answer[MaxN];
bool live[MaxN];
std::vector<int> g[MaxN];
int find(int u)
{
    return ref[u] == u ? u : ref[u] = find(ref[u]);
}
void merge(int u, int v)
{
    if (find(u) == find(v))
    {
        return;
    }
    block--;
    ref[find(v)] = find(u);
}
void addNode(int u)
{
    for (const auto &v : g[u])
    {
        if (live[v])
        {
            merge(u, v);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    block = n;
    std::iota(ref + 1, ref + 1 + n, 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u++;
        v++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%d", &k);
    for (int i = 1; i <= n; i++)
    {
        live[i] = true;
    }
    for (int i = 1; i <= k; i++)
    {
        int x;
        scanf("%d", &x);
        x++;
        kill[i] = x;
        live[x] = false;
    }
    for (int u = 1; u <= n; u++)
    {
        if (live[u])
        {
            addNode(u);
        }
    }
    for (int i = k; i >= 1; i--)
    {
        answer[i] = block - i;
        live[kill[i]] = true;
        addNode(kill[i]);
    }
    printf("%d\n", block);
    for (int i = 1; i <= k; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}
