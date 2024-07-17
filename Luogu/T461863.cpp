#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m;
int fd[MaxN];
int like[MaxN];
int color[MaxN];
std::vector<int> in[MaxN];
int find(int x)
{
    if (fd[x] != x)
    {
        fd[x] = find(fd[x]);
    }
    return fd[x];
}
inline void merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx == fy)
    {
        return;
    }
    fd[fy] = fx;
    if (like[fx] != 0 && like[fy] != 0)
    {
        merge(like[fx], like[fy]);
    }
    else
    {
        like[fy] = like[fx];
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        fd[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (like[find(u)] != 0)
        {
            merge(like[find(u)], v);
        }
        else
        {
            like[find(u)] = v;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (color[find(i)] == 0)
        {
            cnt++;
            color[find(i)] = cnt;
        }
        printf("%d\n", color[find(i)]);
    }
    return 0;
}