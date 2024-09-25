#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 3e5 + 5;
int n;
int answer;
int dp[MaxN];
std::vector<int> g[MaxN];
int dfs(int u, int f)
{
    if (g[u].size() == 1 && g[u][0] == f)
    {
        return 1;
    }
    int fi, se;
    fi = se = 0;
    for (auto v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        int r = dfs(v, u);
        if (r > fi)
        {
            se = fi;
            fi = r;
        }
        else if (r > se)
        {
            se = r;
        }
    }
    if (fi != 0 && se != 0)
    {
        answer = std::max(answer, fi + se + int(g[u].size()) - 1);
    }
    return fi + 1 + int(g[u].size()) - 1 - (f != 0 ? 1 : 0);
}
int main()
{
    scanf("%d%*d", &n);
    if (n == 1)
    {
        printf("%d\n", 1);
        return 0;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    answer = std::max(answer, dfs(1, 0));
    printf("%d\n", answer);
    return 0;
}