#include <cmath>
#include <cstdio>
#include <cstdlib>
constexpr int MaxN = 3e4 + 5;
int n, m;
int fd[MaxN];
int rk[MaxN];
int size[MaxN];
int find(int u)
{
    if (fd[u] == u)
    {
        return u;
    }
    int f = find(fd[u]);
    rk[u] += rk[fd[u]];
    fd[u] = f;
    return f;
}
int main()
{
    scanf("%d", &m);
    n = 30000;
    for (int i = 1; i <= n; i++)
    {
        fd[i] = i;
        size[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        char op = '\n';
        for (; op != 'M' && op != 'C';)
        {
            op = getchar();
        }
        if (op == 'M')
        {
            int u, v;
            scanf("%d%d", &u, &v);
            int fu = find(u);
            int fv = find(v);
            if (fu == fv)
            {
                continue;
            }
            rk[fv] += size[fu];
            size[fu] += size[fv];
            fd[fv] = fu;
        }
        else if (op == 'C')
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (find(u) != find(v))
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", std::abs(rk[u] - rk[v]) - 1);
            }
        }
    }
    return 0;
}
