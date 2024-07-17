#include <cstdio>
#include <vector>
constexpr int MaxN = 5e4 + 5;
int n;
int dp[MaxN];
int size[MaxN];
std::vector<int> lk[MaxN];
void dfs(int u, int f)
{
}
void init(int u, int f)
{
    size[u] = 1;
    for (auto v : lk[u])
    {
        if (v == f)
        {
            continue;
        }
        init(v, u);
        size[u] += size[v];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
    }
    return 0;
}