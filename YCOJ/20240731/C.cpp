#include <bitset>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 5e2 + 5;
constexpr int MaxL = 2e3 + 5;
int n, q;
int max;
int p[MaxN];
int id[MaxN];
int st[21][MaxN];
int vis[MaxL];
int depth[MaxN];
int first[MaxN];
std::map<int, int> map;
std::map<int, bool> v;
std::vector<int> dfn;
std::vector<int> prime;
std::vector<int> link[MaxN];
std::bitset<MaxN> bs[MaxN];
inline void init(int limit = std::sqrt(2e6) + 10)
{
    vis[1] = true;
    for (int i = 2; i <= limit; i++)
    {
        if (vis[i])
        {
            continue;
        }
        prime.push_back(i);
        for (int j = 2 * i; j <= limit; j += i)
        {
            vis[j] = true;
        }
    }
}
inline int format(int x)
{
    int res = 1;
    v.clear();
    for (auto k : prime)
    {
        for (; x % k == 0;)
        {
            if (v[k])
            {
                res /= k;
            }
            else
            {
                res *= k;
            }
            v[k] ^= 1;
            x /= k;
        }
    }
    if (x != 1)
    {
        res *= x;
    }
    if (map[res] == 0)
    {
        max++;
        map[res] = max;
    }
    return map[res];
}
void dfs(int u, int f)
{
    depth[u] = depth[f] + 1;
    dfn.push_back(u);
    bs[u] = bs[f];
    bs[u][p[u]] = bs[u][p[u]] ^ 1;
    for (auto v : link[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
        dfn.push_back(u);
    }
}
int mxx(int x, int y)
{
    return first[x] < first[y] ? x : y;
}
int LCA(int x, int y)
{
    if (x > y)
    {
        std::swap(x, y);
    }
    int j = log2(y - x + 1);
    return mxx(st[j][x], st[j][y - (1 << j) + 1]);
}
int main()
{
    init();
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        p[i] = format(p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    dfn.push_back(0);
    dfs(1, 0);
    int m = 2 * n - 1;
    for (int i = 1; i <= m; i++)
    {
        if (first[dfn[i]] == 0)
        {
            first[dfn[i]] = i;
        }
        st[0][i] = dfn[i];
    }
    for (int j = 1; j < 21; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= m; i++)
        {
            st[j][i] = mxx(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    std::bitset<MaxN> temp;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int lca = LCA(x, y);
        temp = bs[x] ^ bs[y];
        temp[p[lca]] = temp[p[lca]] ^ 1;
        printf("%s\n", (depth[x] - depth[lca]) + (depth[y] - depth[lca]) + 1 == temp.count() ? "No" : "Yes");
    }
    return 0;
}