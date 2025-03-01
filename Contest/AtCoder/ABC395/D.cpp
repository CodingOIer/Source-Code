#include <cstdio>
constexpr int MaxN = 2e6 + 5;
int n, q;
int inode;
int pa[MaxN];
int ref[MaxN];
int root[MaxN];
int value[MaxN];
int create()
{
    int id = ++inode;
    pa[id] = id;
    return id;
}
int find(int u)
{
    return pa[u] == u ? u : pa[u] = find(pa[u]);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        int id = create();
        ref[i] = id;
        root[i] = id;
        value[id] = i;
    }
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            int id = create();
            ref[a] = id;
            pa[id] = root[b];
        }
        else if (op == 2)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            int id = create();
            value[id] = b;
            pa[root[a]] = id;
            id = create();
            value[id] = a;
            pa[root[b]] = id;
            root[b] = id - 1;
            root[a] = id;
        }
        else if (op == 3)
        {
            int a;
            scanf("%d", &a);
            printf("%d\n", value[find(ref[a])]);
        }
    }
    return 0;
}
