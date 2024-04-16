#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
constexpr int MaxN = 2e3 + 5;
int n, m;
int fd[MaxN];
std::vector<std::pair<int, std::pair<int, int>>> links;
int find(int x)
{
    if (fd[x] != x)
    {
        fd[x] = find(fd[x]);
    }
    return fd[x];
}
void merge(int x, int y)
{
    if (find(x) == find(y))
    {
        return;
    }
    fd[find(y)] = find(x);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        links.push_back({w, {u, v}});
    }
    for (int i = 1; i <= n; i++)
    {
        fd[i] = i;
    }
    std::sort(links.begin(), links.end());
    int answer = 0;
    for (auto l : links)
    {
        if (find(l.second.first) == find(l.second.second))
        {
            continue;
        }
        answer = l.first;
        merge(l.second.first, l.second.second);
    }
    printf("%d\n", answer);
    return 0;
}