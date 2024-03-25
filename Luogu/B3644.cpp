#include <cstdio>
#include <queue>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int n;
int cnt[MaxN];
std::queue<int> queue;
std::vector<int> link[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (;;)
        {
            int x;
            scanf("%d", &x);
            if (x == 0)
            {
                break;
            }
            cnt[x]++;
            link[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            queue.push(i);
        }
    }
    for (; !queue.empty();)
    {
        int x = queue.front();
        queue.pop();
        printf("%d ", x);
        for (auto next : link[x])
        {
            cnt[next]--;
            if (cnt[next] == 0)
            {
                queue.push(next);
            }
        }
    }
    return 0;
}