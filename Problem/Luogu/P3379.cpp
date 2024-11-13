#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
const int MaxN = 5e5 + 5;
int u, v;
int vis_cnt;
int n, m, root;
int first[MaxN];
int vis[2 * MaxN];
int st[25][2 * MaxN];
std::vector<int> links[MaxN];
void dfs(int x, int fa)
{
    vis_cnt++;
    vis[vis_cnt] = x;
    for (int next : links[x])
    {
        if (next == fa)
        {
            continue;
        }
        dfs(next, x);
        vis_cnt++;
        vis[vis_cnt] = x;
    }
}
int min(int x, int y)
{
    if (first[x] < first[y])
    {
        return x;
    }
    else
    {
        return y;
    }
    return std::min(first[x], first[y]);
}
int query(int l, int r)
{
    int len = log2(r - l + 1);
    return min(st[len][l], st[len][r - (1 << len) + 1]);
}
int main()
{
    scanf("%d%d%d", &n, &m, &root);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        links[u].push_back(v);
        links[v].push_back(u);
    }
    dfs(root, 0);
    for (int i = 1; i <= vis_cnt; i++)
    {
        if (first[vis[i]] == 0)
        {
            first[vis[i]] = i;
        }
    }
    for (int i = 1; i <= vis_cnt; i++)
    {
        st[0][i] = vis[i];
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= vis_cnt; i++)
        {
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        printf("%d\n", query(std::min(first[u], first[v]), std::max(first[u], first[v])));
    }
    return 0;
}