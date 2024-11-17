#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, x, y;
int p[MaxN];
int cnt[MaxN];
int answer[MaxN];
std::queue<int> que;
std::vector<int> v;
std::vector<int> w[MaxN];
std::priority_queue<std::tuple<int, int>> queue;
inline void solve()
{
    memset(cnt, 0, sizeof(cnt));
    v.clear();
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; i++)
    {
        w[i].clear();
        scanf("%d", &p[i]);
    }
    w[n + 1].clear();
    for (int i = 1; i <= n; i++)
    {
        w[p[i]].push_back(i);
    }
    int undefine = -1;
    for (int i = 1; i <= n + 1; i++)
    {
        if (!w[i].empty())
        {
            queue.push({w[i].size(), i});
        }
        else
        {
            undefine = i;
        }
    }
    for (int i = 1; i <= x; i++)
    {
        auto [k, id] = queue.top();
        queue.pop();
        k--;
        answer[*w[id].rbegin()] = id;
        w[id].pop_back();
        if (k != 0)
        {
            queue.push({k, id});
        }
    }
    for (; !queue.empty();)
    {
        auto [k, id] = queue.top();
        queue.pop();
        cnt[id] = k;
        for (int i = 1; i <= k; i++)
        {
            v.push_back(id);
        }
    }
    std::sort(v.begin(), v.end());
    int l = int(v.size() + 1) / 2;
    std::vector<std::tuple<int, int>> can;
    for (int i = 0; i < int(v.size()); i++)
    {
        if (v[i] != v[(i + l) % int(v.size())])
        {
            can.push_back({v[i], v[(i + l) % int(v.size())]});
        }
        else
        {
            cnt[v[i]]--;
            answer[*w[v[i]].rbegin()] = undefine;
            w[v[i]].pop_back();
        }
    }
    int to = y - x;
    if (int(can.size()) < to)
    {
        printf("No\n");
        return;
    }
    for (int i = 0; i < to; i++)
    {
        answer[*w[std::get<0>(can[i])].rbegin()] = std::get<1>(can[i]);
        w[std::get<0>(can[i])].pop_back();
        cnt[std::get<0>(can[i])]--;
    }
    for (int i = 1; i <= n + 1; i++)
    {
        for (; cnt[i] != 0;)
        {
            cnt[i]--;
            answer[*w[i].rbegin()] = undefine;
            w[i].pop_back();
        }
    }
    printf("Yes\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");
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
