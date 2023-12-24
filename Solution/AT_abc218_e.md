## [ABC218E] Destruction 题解

### 思路分析

这道题的题意是去掉一些边，使得去掉的边权值和最大，且剩下的图连通。

转换一下就是选出一些边，使得这些边的权值最小，且图连通。

这不是最小生成树模板吗？

但是要注意一个细节：这道题中存在负权边，此时不管是否连通，都因该留下这条边，因为这条边的贡献为负。

### 代码实现

下面是使用 [Kruskal](https://oi-wiki.org/graph/mst/#kruskal-%E7%AE%97%E6%B3%95) 算法实现的本题代码：

```cpp
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
```

附：[P3366 【模板】最小生成树](https://www.luogu.com.cn/problem/P3366)