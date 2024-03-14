#include <cstdio>
#include <cstring>
#include <queue>
constexpr int MaxN = 3e6 + 5;
int n, m;
int p[MaxN];
int dist[MaxN];
std::queue<int> queue;
int main()
{
    scanf("%d%d", &n, &m);
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        dist[p[i]] = 0;
        queue.push(p[i]);
    }
    for (; !queue.empty();)
    {
        int x = queue.front();
        queue.pop();
        for (int i = 0; i <= m; i++)
        {
            int l = x ^ (1 << i);
            if (dist[x] + 1 < dist[l])
            {
                dist[l] = dist[x] + 1;
                queue.push(l);
            }
        }
    }
    int full = (1 << (m + 1)) - 1;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", m - dist[full ^ p[i]] + 1);
    }
    printf("\n");
    return 0;
}