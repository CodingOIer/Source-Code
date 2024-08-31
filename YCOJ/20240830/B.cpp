#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, q;
int p[MaxN];
int fi[MaxN];
int dep[MaxN];
int last[MaxN];
int st[28][2 * MaxN];
bool save[MaxN];
std::vector<int> dfn;
std::vector<int> g[MaxN];
std::queue<std::tuple<int, int, int>> temp;
std::priority_queue<std::tuple<int, int, int>> queue;
void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    dfn.push_back(u);
    for (auto v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
        dfn.push_back(u);
    }
}
inline int tin(int x, int y)
{
    return fi[x] < fi[y] ? x : y;
}
inline int LCA(int x, int y)
{
    int l, r;
    l = fi[x];
    r = fi[y];
    if (l > r)
    {
        std::swap(l, r);
    }
    int k = log2(r - l + 1);
    return tin(st[k][l], st[k][r - (1 << k) + 1]);
}
inline int dis(int x, int y)
{
    return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        queue.push(std::tuple<int, int, int>{p[i], i, 0});
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfn.push_back(0);
    dfs(1, 1);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        if (fi[dfn[i]] == 0)
        {
            fi[dfn[i]] = i;
        }
        st[0][i] = dfn[i];
    }
    for (int j = 1; j < 28; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= 2 * n - 1; i++)
        {
            st[j][i] = tin(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int _ = 1; _ <= q; _++)
    {
        int op, t, pt;
        scanf("%d%d%d", &op, &t, &pt);
        if (op == 1)
        {
            bool f = last[pt] != t;
            p[pt] -= t - last[pt];
            p[pt] = std::max(0, p[pt]);
            last[pt] = t;
            save[pt] = true;
            if (f)
            {
                queue.push(std::tuple<int, int, int>{p[pt], pt, t});
            }
        }
        else if (op == 2)
        {
            bool f = last[pt] != t;
            last[pt] = t;
            save[pt] = false;
            if (f)
            {
                queue.push(std::tuple<int, int, int>{p[pt], pt, t});
            }
        }
        else if (op == 3)
        {
            int answer = 0;
            for (; !queue.empty();)
            {
                int x, id, cur;
                std::tie(x, id, cur) = queue.top();
                queue.pop();
                if (cur == last[id])
                {
                    if (x < answer)
                    {
                        temp.push(std::tuple<int, int, int>{x, id, cur});
                        break;
                    }
                    if (!save[id])
                    {
                        x -= t - last[id];
                        x = std::max(0, x);
                    }
                    cur = t;
                    last[id] = t;
                    p[id] = x;
                    temp.push(std::tuple<int, int, int>{x, id, cur});
                    answer = std::max(answer, x - (save[id] ? 0 : dis(pt, id)));
                }
            }
            for (; !temp.empty();)
            {
                queue.push(temp.front());
                temp.pop();
            }
            printf("%d\n", answer);
        }
    }
    return 0;
}