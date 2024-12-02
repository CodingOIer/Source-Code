#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, m;
int p[MaxN];
int b[MaxN];
int pre[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    pre[0] = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = std::min(pre[i - 1], p[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        l = 1;
        r = n;
        int res = -1;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (pre[mid] <= b[i])
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
