#include <algorithm>
#include <cstdio>
#include <vector>
const int MaxN = 1e5 + 5;
int n, q;
int id_cnt;
int id[MaxN];
int fa[MaxN];
int son[MaxN];
int top[MaxN];
int size[MaxN];
int depth[MaxN];
int value[MaxN];
int tree_value[MaxN];
std::vector<int> link[MaxN];
int tree[4 * MaxN];
int lazy[4 * MaxN];
void build(int root, int s, int t)
{
}
void dfsInformation(int root, int fat, int deep)
{
    fa[root] = fat;
    size[root] = 1;
    depth[root] = deep;
    for (int next : link[root])
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
void dfsSplit(int root, int fat, int top_root)
{
    id_cnt++;
    id[root] = id_cnt;
    tree_value[id[root]] = value[root];
    top[root] = top_root;
    if (son[root] == 0)
    {
        return;
    }
    dfsSplit(son[root], root, top_root);
    for (int next : link[root])
    {
        if (next == fat || next == son[root])
        {
            continue;
        }
        dfsSplit(next, root, next);
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &value[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    dfsInformation(1, 0, 1);
    dfsSplit(1, 0, 1);
    return 0;
}