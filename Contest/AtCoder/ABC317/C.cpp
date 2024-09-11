#include <cmath>
#include <cstdio>
#include <vector>
const int inf = 0x3f3f3f3f;
const int MaxN = 1e1 + 5;
const int MaxM = 1e2 + 5;
long long n, m;
long long answer;
long long u, v, l;
bool vis[MaxN];
std::vector<std::pair<long long, long long>> map[MaxN];
void dfs(long long x, long long cnt)
{
    answer = std::max(answer, cnt);
    vis[x] = true;
    for (int i = 0; i < (int)(map[x].size()); i++)
    {
        if (vis[map[x][i].first])
        {
            continue;
        }
        dfs(map[x][i].first, cnt + map[x][i].second);
    }
    vis[x] = false;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &l);
        map[u].push_back({v, l});
        map[v].push_back({u, l});
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 0);
    }
    printf("%lld\n", answer);
    return 0;
}