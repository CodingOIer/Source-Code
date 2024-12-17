#include <cstdio>
#include <string>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, q;
int answer;
char s[MaxN];
char t[MaxN];
std::vector<char> g[MaxN];
void dfs(int u, int f, int end, std::string str)
{
    str += s[u];
    if (u == end)
    {
        int l = str.size();
        for (int j = 1; j < (1 << l); j++)
        {
            std::string k;
            for (int i = 1; i <= l; i++)
            {
                if ((1 >> (i - 1)) & 1)
                {
                    k += str[i - 1];
                }
            }
            if (k == t)
            {
                answer++;
            }
        }
        return;
    }
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u, end, str);
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%s", s + 1);
    scanf("%s", t);
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        answer = 0;
        dfs(u, 0, v, "");
        printf("%d\n", answer);
    }
    return 0;
}
