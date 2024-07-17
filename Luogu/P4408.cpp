#include <cstdio>
#include <utility>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
std::vector<int> lk[MaxN];
std::vector<int> len[MaxN];
std::vector<int> rev[MaxN];
std::pair<int, long long> dfs(int u, int fa)
{
    int pfi;
    long long fi;
    fi = 0;
    pfi = u;
    for (int j = 0; j < lk[u].size(); j++)
    {
        int v = lk[u][j];
        if (v == fa)
        {
            continue;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        lk[u].push_back(v);
        lk[v].push_back(u);
        len[u].push_back(w);
        len[v].push_back(w);
        rev[u].push_back(lk[v].size() - 1);
        rev[v].push_back(lk[u].size() - 1);
    }
    return 0;
}