#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int n, k;
int answer;
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
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        fd[i] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        links.push_back({w, {u, v}});
    }
    std::sort(links.begin(), links.end());
    for (auto l : links)
    {
        if (find(l.second.first) != find(l.second.second))
        {
            merge(l.second.first, l.second.second);
        }
        else
        {
            answer += l.first;
        }
    }
    printf("%d\n", answer);
    return 0;
}