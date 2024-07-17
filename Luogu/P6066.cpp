#include <cstdio>
#include <vector>
constexpr int MaxN = 1e4 + 5;
int n, m;
std::vector<int> lk[MaxN];
std::vector<int> re[MaxN];
std::vector<bool> fl[MaxN];
void dfs(int u)
{
    printf("%d\n", u);
    for (int j = 0; j < lk[u].size(); j++)
    {
        if (fl[u][j])
        {
            continue;
        }
        fl[u][j] = true;
        fl[lk[u][j]][re[u][j]] = true;
        dfs(lk[u][j]);
        printf("%d\n", u);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        lk[u].push_back(v);
        lk[v].push_back(u);
        re[u].push_back(lk[v].size() - 1);
        re[v].push_back(lk[u].size() - 1);
        fl[u].push_back(false);
        fl[v].push_back(false);
    }
    dfs(1);
    return 0;
}