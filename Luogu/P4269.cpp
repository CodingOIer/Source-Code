#include <algorithm>
#include <cstdio>
#include <utility>
constexpr int MaxN = 1e5 + 5;
int max;
int n, m;
int h[MaxN];
int fd[MaxN];
int size[MaxN];
bool answer[MaxN];
std::pair<int, int> p[MaxN];
std::pair<std::pair<int, int>, int> q[MaxN];
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
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
    {
        return;
    }
    size[fx] += size[fy];
    fd[fy] = fx;
    max = std::max(max, size[fx]);
}
inline void add(int x)
{
    size[x] = 1;
    max = std::max(max, 1);
    if (size[x - 1] != 0)
    {
        merge(x - 1, x);
    }
    if (size[x + 1] != 0)
    {
        merge(x, x + 1);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        fd[i] = i;
        size[i] = 0;
        scanf("%d", &h[i]);
        p[i].first = h[i];
        p[i].second = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &q[i].first.first, &q[i].first.second);
        q[i].second = i;
    }
    std::sort(p + 1, p + 1 + n, [](const auto &__x, const auto &__y) { return __x.first > __y.first; });
    std::sort(q + 1, q + 1 + m, [](const auto &__x, const auto &__y) { return __x.first.first > __y.first.first; });
    int j = 1;
    for (int i = 1; i <= m; i++)
    {
        for (; j <= n && p[j].first > q[i].first.first;)
        {
            add(p[j].second);
            j++;
        }
        answer[q[i].second] = max < q[i].first.second;
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", answer[i] ? 1 : 0);
    }
    return 0;
}