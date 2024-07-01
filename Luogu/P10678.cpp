#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
std::queue<int> queue;
std::vector<std::pair<int, int>> v;
void solve()
{
    scanf("%d", &n);
    v.clear();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        v.push_back({-p[i], i});
    }
    std::sort(v.begin(), v.end());
    for (int i = 1; i <= -v[0].first; i++)
    {
        queue.push(v[0].second);
    }
    for (int j = 1; j < n; j++)
    {
        printf("%d %d\n", queue.front(), v[j].second);
        queue.pop();
        for (int i = 1; i < p[v[j].second]; i++)
        {
            queue.push(v[j].second);
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}