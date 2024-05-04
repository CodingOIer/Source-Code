#include <cstdio>
#include <vector>
constexpr int MaxN = 1e3 + 5;
int idx;
int n, m;
int id[MaxN];
int rev[MaxN][MaxN];
int was_beat[MaxN];
std::vector<int> use[MaxN];
std::vector<int> max[MaxN];
std::vector<int> link[MaxN];
inline void init()
{
    idx = 0;
    for (int i = 0; i < MaxN; i++)
    {
        use[i].clear();
        max[i].clear();
        link[i].clear();
    }
}
inline void add(int u, int v, int m, int k)
{
    use[u].push_back(k);
    max[u].push_back(m);
    link[u].push_back(v);
    rev[v][u] = link[u].size();
}
inline void add(int u, int v, int m)
{
    add(u, v, m, 0);
    add(v, u, m, m);
}
inline int new_node()
{
    idx++;
    return idx;
}
inline int dinic int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        was_beat[v]++;
    }
    for (int x = 1; x <= n; x++)
    {
        init();
        int s = new_node();
        int t = new_node();
        int mx = (n - 1) - was_beat[x];
        for (int i = 1; i <= n; i++)
        {
            if (i == x)
            {
                continue;
            }
            id[i] = new_node();
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == x)
            {
                continue;
            }
            for (int j = i + 1; j <= n; j++)
            {
                if (j == x)
                {
                    continue;
                }
                int contest = new_node();
                add(s, contest, 1, 0);
                add(contest, id[i], 1, 0);
                add(contest, id[j], 1, 0);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == x)
            {
                continue;
            }
            add(id[i], t, mx - 1, mx - 1);
        }
    }
    return 0;
}