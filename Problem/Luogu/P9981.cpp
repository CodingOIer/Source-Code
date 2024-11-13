#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m;
int in[MaxN];
int answer[MaxN];
int last_vis[MaxN];
long long sum[MaxN];
std::vector<std::pair<int, int>> link[MaxN];
std::priority_queue<std::pair<int, int>> queue;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        in[u]++;
        link[v].push_back({u, l});
    }
    for (int i = 1; i <= n; i++)
    {
        last_vis[i] = 0x3f3f3f3f;
        std::sort(link[i].begin(), link[i].end(),
                  [](const auto &__x, const auto &__y) { return __x.second < __y.second; });
        if (in[i] == 0)
        {
            queue.push({0, i});
        }
    }
    for (; !queue.empty();)
    {
        auto pa = queue.front();
        int x = pa.queue.pop();
        for (auto next : link[x])
        {
            int v, l;
            v = next.first;
            l = next.second;
            if (answer[x] + 1 > answer[v] || (answer[x] + 1 == answer[v] && l < last_vis[v]))
            {
                answer[v] = answer[x] + 1;
                last_vis[v] = l;
                sum[v] = sum[x] + l;
            }
            in[v]--;
            if (in[v] == 0)
            {
                queue.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d %lld\n", answer[i], sum[i]);
    }
    return 0;
}