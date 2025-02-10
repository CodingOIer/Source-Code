#include <cassert>
#include <cstdio>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m;
int pa[MaxN];
std::vector<std::tuple<int, int, int>> answer;
std::vector<std::tuple<int, int, int>> more[MaxN];
std::priority_queue<std::tuple<int, int>> queue;
int find(int u)
{
    return pa[u] == u ? u : pa[u] = find(pa[u]);
}
void merge(int u, int v, int ou, int ov, int id)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        if (id != 0)
        {
            more[u].push_back({ou, ov, id});
        }
        return;
    }
    if (more[u].size() < more[v].size())
    {
        for (const auto &val : more[u])
        {
            more[v].push_back(val);
        }
        pa[u] = v;
    }
    else
    {
        for (const auto &val : more[v])
        {
            more[u].push_back(val);
        }
        pa[v] = u;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    std::iota(pa + 1, pa + n + 1, 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        merge(u, v, u, v, i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (find(i) != i)
        {
            continue;
        }
        queue.push({more[i].size(), find(i)});
    }
    for (; int(queue.size()) >= 2;)
    {
        auto [_a, u] = queue.top();
        queue.pop();
        auto [_b, v] = queue.top();
        queue.pop();
        auto [x, y, id] = more[u].back();
        if (find(x) == u)
        {
            answer.push_back({id, y, v});
        }
        else if (find(y) == u)
        {
            answer.push_back({id, x, v});
        }
        more[u].pop_back();
        merge(u, v, 0, 0, 0);
        queue.push({more[find(u)].size(), find(u)});
    }
    printf("%d\n", int(answer.size()));
    for (const auto &[id, x, y] : answer)
    {
        printf("%d %d %d\n", id, x, y);
    }
    return 0;
}
