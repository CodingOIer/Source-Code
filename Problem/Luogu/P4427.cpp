#include <cstdio>
#include <vector>
const int MaxN = 3e5 + 5;
const int MaxK = 3e1 + 5;
const long long Mod = 998244353;
int n, m;
int id_cnt;
int id[MaxN];
int fa[MaxN];
int son[MaxN];
int top[MaxN];
int size[MaxN];
int depth[MaxN];
long long sum[MaxN][MaxK];
long long power[MaxN][MaxK];
std::vector<int> link[MaxN];
void dfsInformation(long long root, long long fat, long long deep)
{
    fa[root] = fat;
    size[root] = 1;
    depth[root] = deep;
    for (long long next : link[root])
    {
        if (next == fat)
        {
            continue;
        }
        dfsInformation(next, root, deep + 1);
        size[root] += size[next];
        if (size[next] > size[son[root]])
        {
            son[root] = next;
        }
    }
    return;
}
void dfsSplit(long long root, long long fat, long long top_root)
{
    id_cnt++;
    id[root] = id_cnt;
    top[root] = top_root;
    if (son[root] == 0)
    {
        return;
    }
    dfsSplit(son[root], root, top_root);
    for (long long next : link[root])
    {
        if (next == fat || next == son[root])
        {
            continue;
        }
        dfsSplit(next, root, next);
    }
}
long long query(int x, int y, int k)
{
    long long res = 0;
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        res = (res + sum[id[x]][k] - sum[id[top[x]] - 1][k] + Mod) % Mod;
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    res = (res + sum[id[y]][k] - sum[id[x]][k] + Mod) % Mod;
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    dfsInformation(1, 0, 1);
    dfsSplit(1, 0, 1);
    for (int i = 1; i <= n; i++)
    {
        power[i][0] = 1;
        for (int j = 1; j <= 30; j++)
        {
            power[i][j] = power[i][j - 1] * depth[i] % Mod;
        }
    }
    for (int i = 0; i <= 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[j][i] = (sum[j - 1][i] + power[j][i]) % Mod;
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, k;
        scanf("%d%d%d", &u, &v, &k);
        printf("%lld\n", query(u, v, k));
    }
    return 0;
}