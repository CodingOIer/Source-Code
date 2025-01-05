#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
constexpr int MaxN = 5e3 + 5;
int n;
int p[MaxN];
int fa[MaxN];
int fi[MaxN];
int lg2[MaxN * 2];
int temp[MaxN];
int answer[MaxN];
int st[21][MaxN * 2];
std::vector<int> dfn;
std::vector<int> g[MaxN];
void dfsInit(int u, int f)
{
    fa[u] = f;
    dfn.push_back(u);
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfsInit(v, u);
        dfn.push_back(u);
    }
}
int topLCA(int u, int v)
{
    return fi[u] < fi[v] ? u : v;
}
int LCA(int u, int v)
{
    int l = std::min(fi[u], fi[v]);
    int r = std::max(fi[u], fi[v]);
    int j = lg2[r - l + 1];
    return topLCA(st[j][l], st[j][r - (1 << j) + 1]);
}
void dfsCalc(int u, int f)
{
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfsCalc(v, u);
        temp[u] = std::min(temp[u], temp[v]);
    }
}
int main()
{
    scanf("%d", &n);
    if (n > 5e3)
    {
        return 0;
    }
    lg2[1] = 0;
    for (int i = 2; i <= 2 * n - 1; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        answer[i] = -1;
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfn.push_back(0);
    dfsInit(1, 0);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        st[0][i] = dfn[i];
        fi[dfn[i]] = fi[dfn[i]] == 0 ? i : fi[dfn[i]];
    }
    for (int j = 1; j <= 19; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= 2 * n - 1; i++)
        {
            st[j][i] = topLCA(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            temp[j] = 0x3f3f3f3f;
        }
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            int l = LCA(i, j);
            temp[l] = std::min(temp[l], p[i] ^ p[j]);
        }
        dfsCalc(1, 0);
        int u = i;
        for (;;)
        {
            if (temp[u] != 0x3f3f3f3f)
            {
                answer[u] = std::max(answer[u], temp[u]);
            }
            if (u == 1)
            {
                break;
            }
            u = fa[u];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}
