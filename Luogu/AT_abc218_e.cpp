#include <algorithm>
#include <cstdio>
void add(int, int);
int find(int);
class edge
{
  public:
    int len;
    int u, v;
    friend bool operator<(const edge &x, const edge &y)
    {
        return x.len < y.len;
    }
};
const int MaxN = 2e5 + 5;
int n, m;
int f[MaxN];
long long min;
long long sum;
edge link[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &link[i].u, &link[i].v, &link[i].len);
        sum += link[i].len;
    }
    std::sort(link + 1, link + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        if (find(link[i].u) != find(link[i].v) || link[i].len < 0)
        {
            add(link[i].u, link[i].v);
            min += link[i].len;
        }
    }
    printf("%lld\n", sum - min);
    return 0;
}
void add(int x, int y)
{
    f[find(y)] = find(x);
}
int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}