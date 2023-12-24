#include <algorithm>
#include <cstdio>
const int MaxN = 2e5 + 5;
int n, m;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int to;
        int l, r;
        l = 1;
        r = m;
        for (; l <= r;)
        {
            int mid;
            mid = (l + r) / 2;
            if (p[mid] >= i)
            {
                to = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", p[to] - i);
    }
    return 0;
}