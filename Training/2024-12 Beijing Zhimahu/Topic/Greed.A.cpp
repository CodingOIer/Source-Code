#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
long long m;
long long answer;
long long p[MaxN];
bool calc(long long x)
{
    long long res = 0;
    for (int i = 1; i <= 2 * x; i++)
    {
        res = std::max(res, (p[i] + p[2 * x - i + 1]) % m);
    }
    for (int i = 2 * x + 1; i <= 2 * n; i++)
    {
        res = std::max(res, (p[i] + p[2 * n - (i - 2 * x) + 1]) % m);
        if (p[i] + p[2 * n - (i - 2 * x) + 1] < m)
        {
            return false;
        }
    }
    answer = std::min(answer, res);
    return true;
}
int main()
{
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + 1 + 2 * n);
    answer = 0x7f7f7f7f'7f7f7f7f;
    int l, r;
    l = 0;
    r = n;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (calc(mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld\n", answer);
    return 0;
}
