#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n, m;
long long k;
int p[MaxN];
int main()
{
    scanf("%d%lld%d", &n, &k, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    int last = n;
    long long sum = 0;
    for (int i = n; i >= 1; i--)
    {
        if (sum + p[i] <= k)
        {
            last = i;
            sum += p[i];
        }
        else
        {
            break;
        }
    }
    int backup = n;
    n = last - 1;
    int l, r;
    l = 0;
    r = 1e6;
    int res = -1;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        long long need = 0;
        for (int i = 1; i <= n; i++)
        {
            need += std::max(0, p[i] - mid);
        }
        if (need <= m)
        {
            r = mid - 1;
            res = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        m -= std::max(0, p[i] - res);
        p[i] = std::min(p[i], res);
    }
    for (int i = n; i >= n - m + 1; i--)
    {
        p[i]--;
    }
    n = backup;
    std::sort(p + 1, p + 1 + n);
    long long answer = 0;
    for (int i = 1; i <= last - 2; i++)
    {
        answer += 1ll * (1 + p[i]) * p[i] / 2;
    }
    long long app = k - p[last - 1];
    answer += ((k - app) + (k - (sum - 1))) * (sum - app) / 2;
    printf("%lld\n", answer);
    return 0;
}