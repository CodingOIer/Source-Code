#include <cstdio>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n, m;
int st[22][MaxN * 2];
int lg2[MaxN * 2];
int depth[MaxN];
int first[MaxN];
std::vector<int> road;
std::vector<int> link[MaxN];
void dfs(int x, int fa, int dep)
{
    depth[x] = dep;
    for (auto next : link[x])
    {
        if (next == fa)
        {
            continue;
        }
        road.push_back(x);
        dfs(next, x, dep + 1);
    }
    road.push_back(x);
}
inline int max(int x, int y)
{
    return first[x] < first[y] ? x : y;
}
inline int LCA(int x, int y)
{
    int l, r;
    l = first[x];
    r = first[y];
    if (l > r)
    {
        l = first[y];
        r = first[x];
    }
    int len = lg2[(r - l + 1)] - 1;
    return max(st[len][l], st[len][r - (1 << len) + 1]);
}
inline int abs(int x)
{
    return x >= 0 ? x : -x;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    dfs(1, 0, 1);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        st[0][i] = road[i - 1];
        if (first[road[i - 1]] != 0)
        {
            continue;
        }
        first[road[i - 1]] = i;
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i <= 2 * n - 1 && i + (1 << j) - 1 <= 2 * n - 1; i++)
        {
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int lxy, lxz, lyz;
        lxy = LCA(x, y);
        lxz = LCA(x, z);
        lyz = LCA(y, z);
        int lca;
        if (lxy == lxz)
        {
            lca = lyz;
        }
        else if (lxy == lyz)
        {
            lca = lxz;
        }
        else if (lxz == lyz)
        {
            lca = lxy;
        }
        int lx, ly, lz;
        lx = LCA(lca, x);
        ly = LCA(lca, y);
        lz = LCA(lca, z);
        int len = abs(depth[x] - depth[lx]) + abs(depth[lca] - depth[lx]) + abs(depth[y] - depth[ly]) +
                  abs(depth[lca] - depth[ly]) + abs(depth[z] - depth[lz]) + abs(depth[lca] - depth[lz]);
        printf("%d %d\n", lca, len);
    }
    return 0;
}