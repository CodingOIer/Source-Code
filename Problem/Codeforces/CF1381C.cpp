#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, x, y;
int p[MaxN];
int answer[MaxN];
std::map<int, int> map;
std::vector<int> v, k;
std::vector<int> w[MaxN];
std::priority_queue<std::tuple<int, int>> queue;
void solve()
{
    v.clear();
    k.clear();
    map.clear();
    memset(answer, 0, sizeof(answer));
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; i++)
    {
        w[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        map[p[i]]++;
        w[p[i]].push_back(i);
    }
    int none = -1;
    for (int i = 1; i <= n + 1; i++)
    {
        if (map[i] == 0)
        {
            none = i;
        }
        else
        {
            queue.push({map[i], i});
        }
    }
    for (int i = 1; i <= x; i++)
    {
        auto [cnt, x] = queue.top();
        queue.pop();
        cnt--;
        answer[*w[x].rbegin()] = x;
        w[x].pop_back();
        if (cnt != 0)
        {
            queue.push({cnt, x});
        }
    }
    for (; !queue.empty();)
    {
        auto [cnt, x] = queue.top();
        queue.pop();
        for (int i = 1; i <= cnt; i++)
        {
            v.push_back(x);
        }
    }
    k = v;
    std::reverse(k.begin(), k.end());
    y -= x;
    for (int i = 0; i < v.size() / 2; i++)
    {
        if (v[i] != k[i] && y >= 1)
        {
            answer[*w[v[i]].rbegin()] = k[i];
            answer[*w[k[i]].rbegin()] = v[i];
            w[v[i]].pop_back();
            w[k[i]].pop_back();
            y -= 2;
        }
    }
    if (y == -1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (answer[i] != p[i] && answer[i] != 0)
            {
                answer[i] = none;
                break;
            }
        }
    }
    else if (y != 0)
    {
        if (y < 0)
        {
            exit(1);
        }
        printf("No\n");
        return;
    }
    printf("Yes\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", answer[i] == 0 ? none : answer[i]);
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