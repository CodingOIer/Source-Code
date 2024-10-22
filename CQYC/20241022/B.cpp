// ~ 100

#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 6e2 + 5;
int n, tp;
bool vi[MaxN];
bool vis[MaxN][MaxN];
std::vector<int> g[MaxN][MaxN];
inline void add(int uid, int u, int v)
{
    g[uid][u].push_back(v);
    g[uid][v].push_back(u);
}
int main()
{
    scanf("%d%d", &n, &tp);
    if (tp == 1)
    {
        int m = n / 2;
        for (int i = 1; i <= m; i++)
        {
            memset(vi, 0, sizeof(vi));
            int start = i;
            int cnt = n - 1;
            vi[i] = true;
            for (int to = i; cnt >= 1;)
            {
                if (start != to && !vis[start][to] && !vi[to])
                {
                    vi[to] = true;
                    cnt--;
                    vis[start][to] = true;
                    vis[to][start] = true;
                    add(i, start, to);
                    start = to;
                }
                to++;
                to = (to - 1) % n + 1;
            }
        }
        printf("%d\n", n / 2);
        for (int i = 1; i <= n / 2; i++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (auto v : g[i][u])
                {
                    if (v > u)
                    {
                        printf("%d %d\n", u, v);
                    }
                }
            }
        }
    }
    else if (tp == 2)
    {
        if (n % 2 == 0)
        {
            int m = n / 2;
            for (int i = 1; i <= n / 2; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    add(i, i, (i + j - 1) % n + 1);
                }
                for (int j = 1; j <= m - 1; j++)
                {
                    add(i, (i + m - 1) % n + 1, (i + m + j - 1) % n + 1);
                }
            }
        }
        else
        {
            int m = n / 2;
            for (int i = 1; i <= n / 2; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    add(i, i, (i + j - 1) % n + 1);
                }
                for (int j = 1; j <= m; j++)
                {
                    add(i, (i + m) % n + 1, (i + m + j) % n + 1);
                }
            }
        }
        printf("%d\n", n / 2);
        for (int i = 1; i <= n / 2; i++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (auto v : g[i][u])
                {
                    if (v > u)
                    {
                        printf("%d %d\n", u, v);
                    }
                }
            }
        }
    }
    return 0;
}