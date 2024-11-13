#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
long long answer[MaxN];
std::vector<int> v[MaxN];
std::vector<long long> sum;
int solve()
{
    memset(answer, 0, sizeof(answer));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        v[i].clear();
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        v[p[i]].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        std::sort(v[i].begin(), v[i].end(), std::greater<>());
        sum.clear();
        sum.push_back(0);
        for (auto x : v[i])
        {
            sum.push_back(*sum.rbegin() + x);
        }
        for (int j = 1; j <= int(v[i].size()); j++)
        {
            answer[j] += sum[int(v[i].size()) / j * j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", answer[i]);
    }
    printf("\n");
    return 0;
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