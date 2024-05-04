#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
constexpr int MaxN = 1e4 + 5;
constexpr int MaxM = 1e6 + 5;
int n, m;
int l[MaxN];
int r[MaxN];
long long p[MaxN];
long long s[MaxN];
long long answer[MaxN];
std::vector<std::pair<int, int>> want[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        s[i] = s[i - 1] + p[i];
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
        want[std::min(l[i], r[i])].push_back({std::max(l[i], r[i]), i});
    }
    for (int i = 1; i <= n; i++)
    {
        std::sort(want[i].begin(), want[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        int w = 0;
        long long xor_sum = 0;
        for (int j = i; j <= n; j++)
        {
            xor_sum ^= s[j] - s[i - 1];
            if (w < want[i].size() && want[i][w].first == j)
            {
                answer[want[i][w].second] = xor_sum;
                w++;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%lld\n", answer[i]);
    }
    return 0;
}