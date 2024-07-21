#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, k;
std::vector<int> link[MaxN];
std::pair<int, long long> calc(int u, int f)
{
    int fi;
    long long lfi;
    fi = u;
    lfi = 0;
    for (auto v : link[u])
    {
        if (v == f)
        {
            continue;
        }
        auto res = calc(v, u);
        res.second++;
        if (res.second > lfi)
        {
            fi = res.first;
            lfi = res.second;
        }
    }
    return {fi, lfi};
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    printf("%lld\n", (calc(calc(1, 0).first, 0).second + 1 - k) / 2);
    return 0;
}