#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
long long n;
long long p[MaxN];
long long sum[MaxN];
long long sort[MaxN];
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        sort[i] = p[i];
    }
    std::sort(sort + 1, sort + n + 1, [](const long long &x, const long long &y) { return x > y; });
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + sort[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        int l = 1, r = n;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (sort[mid] > p[i])
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("%lld ", sum[res]);
    }
    printf("\n");
    return 0;
}