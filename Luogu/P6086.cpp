#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <vector>
constexpr int MaxN = 5e6 + 5;
int n, m;
int p[MaxN];
int in[MaxN];
int par[MaxN];
std::vector<int> v;
std::vector<int> g[MaxN];
void dfs(int v)
{
    for (int u : g[v])
    {
        if (u != par[v])
        {
            par[u] = v;
            dfs(u);
        }
    }
}
void encoding()
{
    exit(0);
    for (int u = 1; u <= n - 1; u++)
    {
        int v;
        scanf("%d", &v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    dfs(n);
    int k = 1;
    for (; v.size() + 2 < n;)
    {
        for (; in[k] != 1;)
        {
            k++;
        }
        int it = k;
        for (; in[it] == 1 && it <= k && v.size() + 2 < n;)
        {
            v.push_back(par[it]);
            in[it]--;
            in[par[it]]--;
            it = par[it];
        }
    }
    long long answer = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        answer ^= 1ll * v[i - 1] * i;
    }
    printf("%lld\n", answer);
}
void decoding()
{
}
int main()
{
    scanf("%d%d", &n, &m);
    if (m == 1)
    {
        encoding();
    }
    else
    {
        decoding();
    }
    return 0;
}