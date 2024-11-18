#include <cstdio>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n;
long long answer;
std::vector<int> g[MaxN];
void dfs(int u, int f)
{
    if (f != 0)
    {
        if (u < f)
        {
            answer -= 1ll * u * (n - f + 1);
        }
        else
        {
            answer -= 1ll * (n - u + 1) * f;
        }
    }
    for (auto v : g[u])
    {
        if (v != f)
        {
            dfs(v, u);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        answer += 1ll * (n - i + 1) * i;
    }
    dfs(1, 0);
    printf("%lld\n", answer);
    return 0;
}
