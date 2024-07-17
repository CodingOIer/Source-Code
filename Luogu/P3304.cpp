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
        auto temp = dfs(v, u);
        temp.second += len[u][j];
        if (temp.second > fi)
        {
            pfi = temp.first;
            fi = temp.second;
        }
    }
    return {pfi, fi};
}
bool flag(int u, int fa, int t)
{
    if (u == t)
    {
        return true;
    }
    for (int j = 0; j < lk[u].size(); j++)
    {
        int v = lk[u][j];
        if (v == fa)
        {
            continue;
        }
        if (flag(v, u, t))
        {
            len[u][j]--;
            len[v][rev[u][j]]--;
            return true;
        }
    }
    return false;
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
    int s = dfs(1, 0).first;
    auto res = dfs(s, 0);
    printf("%lld\n", res.second);
    flag(s, 0, res.first);
    printf("%lld\n", res.second - dfs(dfs(1, 0).first, 0).second);
    return 0;
}