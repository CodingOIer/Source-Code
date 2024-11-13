#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m, k;
char s[MaxN];
std::vector<std::tuple<int, int, int>> v;
int main()
{
    scanf("%d%d", &k, &m);
    scanf("%s", s + 1);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l++;
        x++;
        v.push_back({l, r, x});
    }
    std::reverse(v.begin(), v.end());
    for (int i = 1; i <= k; i++)
    {
        int w = i;
        for (auto [l, r, x] : v)
        {
            int len = r - l + 1;
            if (w < x)
            {
                continue;
            }
            else if (w < x + len)
            {
                w = l + (w - x);
            }
            else
            {
                w -= len;
            }
        }
        printf("%c", s[w]);
    }
    printf("\n");
    return 0;
}