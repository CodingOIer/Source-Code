#include <algorithm>
#include <cstdio>
#include <vector>
const int MaxM = 1e5 + 5;
const int MaxN = 1e3 + 5;
class edge
{
  public:
    int u, v;
    int time;
};
int n, m;
int still;
int f[MaxN];
edge links[MaxM];
int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
void link(int x, int y)
{
    f[find(y)] = find(x);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &links[i].u, &links[i].v, &links[i].time);
    }
    std::sort(links + 1, links + 1 + m, [](edge a, edge b) { return a.time < b.time; });
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    still = n;
    for (int i = 1; i <= m; i++)
    {
        if (find(links[i].u) != find(links[i].v))
        {
            still--;
        }
        link(links[i].u, links[i].v);
        if (still == 1)
        {
            printf("%d\n", links[i].time);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}