#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
constexpr int MaxN = 1e3 + 5;
int n, m, k;
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
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        links.push_back({w, {u, v}});
    }
    std::sort(links.begin(), links.end());
    for (int i = 1; i <= n; i++)
    {
        fd[i] = i;
    }
    if (n == k)
    {
        printf("0\n");
        return 0;
    }
    int all = n;
    int answer = 0;
    for (auto l : links)
    {
        if (find(l.second.first) == find(l.second.second))
        {
            continue;
        }
        merge(l.second.first, l.second.second);
        answer += l.first;
        all--;
        if (all == k)
        {
            printf("%d\n", answer);
            return 0;
        }
    }
    printf("No Answer\n");
    return 0;
}