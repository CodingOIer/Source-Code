#include <algorithm>
#include <cstdio>
#include <numeric>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m, k;
int fd[MaxN];
int cntA[MaxN];
int cntB[MaxN];
std::vector<std::tuple<int, int, int>> links;
int find(int u)
{
    return fd[u] == u ? u : fd[u] = find(fd[u]);
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        links.push_back({w, u, v});
    }
    std::sort(links.begin(), links.end());
    std::iota(fd + 1, fd + 1 + n, 1);
    for (int i = 1; i <= k; i++)
    {
        int x;
        scanf("%d", &x);
        cntA[x]++;
    }
    for (int i = 1; i <= k; i++)
    {
        int x;
        scanf("%d", &x);
        cntB[x]++;
    }
    long long answer = 0;
    for (const auto &[w, u, v] : links)
    {
        if (find(u) == find(v))
        {
            continue;
        }
        int fu, fv;
        fu = find(u);
        fv = find(v);
        int rm = std::min(cntA[fu], cntB[fv]);
        answer += 1ll * rm * w;
        cntA[fu] -= rm;
        cntB[fv] -= rm;
        rm = std::min(cntB[fu], cntA[fv]);
        answer += 1ll * rm * w;
        cntB[fu] -= rm;
        cntA[fv] -= rm;
        cntA[fu] += cntA[fv];
        cntB[fu] += cntB[fv];
        fd[find(v)] = find(u);
    }
    printf("%lld\n", answer);
    return 0;
}
