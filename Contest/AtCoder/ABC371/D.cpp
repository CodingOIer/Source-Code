#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, q;
long long sum[MaxN];
std::vector<int> v;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int x, y;
        x = std::lower_bound(v.begin(), v.end(), l) - v.begin() + 1;
        y = std::upper_bound(v.begin(), v.end(), r) - v.begin();
        printf("%lld\n", sum[y] - sum[x - 1]);
    }
    return 0;
}