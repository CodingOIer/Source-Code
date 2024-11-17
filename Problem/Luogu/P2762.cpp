#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e2 + 5;
constexpr int MaxM = 1e3 + 5;
int n, m;
int p[MaxN];
int id[MaxN];
int w[MaxN][MaxN];
int cost[MaxN];
char *ptr;
char buf[MaxM];
std::queue<int> queue;
std::vector<int> v[MaxN];
std::vector<std::tuple<int, int, int>> g[MaxN];
std::vector<std::tuple<int, int, int>>::iterator cur[MaxN];
inline void readLine()
{
    ptr = buf;
    scanf(" ");
    scanf("%[^\n]", buf);
}
inline char getcharBuf()
{
    return (*ptr == '\0' ? '\0' : *(ptr++));
}
inline int read()
{
    char ch;
    int res = 0;
    for (;;)
    {
        ch = getcharBuf();
        if (ch == '\0' && res == 0)
        {
            return -1;
        }
        if (std::isdigit(ch))
        {
            res = ch ^ 48;
            break;
        }
    }
    for (;;)
    {
        ch = getcharBuf();
        if (ch == '\0' && res == 0)
        {
            return -1;
        }
        if (isdigit(ch))
        {
            res = res * 10 + (ch ^ 48);
        }
        else
        {
            break;
        }
    }
    return res;
}
inline void addEdge(int u, int v, int mx)
{
    w[u][v] = g[u].size();
    w[v][u] = g[v].size();
    g[u].push_back({v, 0, mx});
    g[v].push_back({u, mx, mx});
}
inline void bfs()
{
    for (int i = 1; i <= n + m + 2; i++)
    {
        cur[i] = g[i].begin();
    }
    memset(id, 0x3f, sizeof(id));
    id[1] = 1;
    queue.push(1);
    for (; !queue.empty();)
    {
        auto u = queue.front();
        queue.pop();
        for (auto [v, use, max] : g[u])
        {
            if (use >= max)
            {
                continue;
            }
            if (id[v] != 0x3f3f3f3f)
            {
                continue;
            }
            id[v] = id[u] + 1;
            queue.push(v);
        }
    }
}
int tryPush(int u, int canPush)
{
    if (u == 2 + n + m || canPush == 0)
    {
        return canPush;
    }
    for (auto &it = cur[u]; it != g[u].end(); it++)
    {
        if (id[u] + 1 == id[std::get<0>(*it)] && std::get<1>(*it) < std::get<2>(*it))
        {
            int push = std::min(canPush, std::get<2>(*it) - std::get<1>(*it));
            push = tryPush(std::get<0>(*it), push);
            if (push != 0)
            {
                std::get<1>(*it) += push;
                std::get<1>(g[std::get<0>(*it)][w[std::get<0>(*it)][u]]) -= push;
                return push;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        readLine();
        p[i] = read();
        for (int x = read(); x != -1; x = read())
        {
            v[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cost[i]);
    }
    int s, t;
    s = 1;
    t = n + m + 2;
    for (int i = 1; i <= m; i++)
    {
        addEdge(s, 1 + i, p[i]);
        for (auto to : v[i])
        {
            addEdge(1 + i, 1 + m + to, 0x3f3f3f3f);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        addEdge(1 + m + i, t, cost[i]);
    }
    for (;;)
    {
        bfs();
        if (id[t] == 0x3f3f3f3f)
        {
            break;
        }
        tryPush(1, 0x3f3f3f3f);
        // printf("Push %d\n", push);
    }
    std::set<int> tool;
    for (int i = 1; i <= n; i++)
    {
        if (id[1 + m + i] != 0x3f3f3f3f)
        {
            tool.insert(i);
        }
    }
    std::vector<int> have;
    for (int i = 1; i <= m; i++)
    {
        bool suc = true;
        for (auto to : v[i])
        {
            auto it = tool.lower_bound(to);
            suc &= it != tool.end() && *it == to;
        }
        if (suc)
        {
            have.push_back(i);
        }
    }
    int answer = 0;
    for (const auto &val : have)
    {
        answer += p[val];
        printf("%d ", val);
    }
    printf("\n");
    for (const auto &val : tool)
    {
        answer -= cost[val];
        printf("%d ", val);
    }
    printf("\n");
    printf("%d\n", answer);
    return 0;
}
