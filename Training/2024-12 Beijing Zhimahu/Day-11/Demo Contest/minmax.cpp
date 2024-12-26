#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int answer = 0;
    for (int j = 1; j < (1 << n) - 1; j++)
    {
        std::vector<int> b, c;
        for (int i = 1; i <= n; i++)
        {
            if ((j >> (i - 1)) & 1)
            {
                b.push_back(p[i]);
            }
            else
            {
                c.push_back(p[i]);
            }
        }
        int preMax = -0x3f3f3f3f;
        int preMaxCount = 0;
        for (const auto &val : b)
        {
            if (val >= preMax)
            {
                preMax = val;
                preMaxCount++;
            }
        }
        int preMin = 0x3f3f3f3f;
        int preMinCount = 0;
        for (const auto &val : c)
        {
            if (val <= preMin)
            {
                preMin = val;
                preMinCount++;
            }
        }
        answer = std::max(answer, preMaxCount + preMinCount);
    }
    printf("%d\n", answer);
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
