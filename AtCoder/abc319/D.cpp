#include <algorithm>
#include <cstdio>
const int MaxN = 2e5 + 5;
long long max;
long long n, m;
long long len[MaxN];
bool check(long long x)
{
    long long have;
    long long line;
    long long first;
    have = 0;
    line = 0;
    first = 0;
    for (int i = 1; i <= n; i++)
    {
        if (have < len[i] + 1)
        {
            line++;
            have = x;
            first = 1;
            if (line > m)
            {
                return false;
            }
        }
        if (first == 1)
        {
            have++;
            first = 0;
        }
        have -= len[i] + 1;
    }
    return true;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &len[i]);
        max = std::max(max, len[i]);
    }
    long long l, r;
    long long result;
    l = max;
    r = 1e18;
    result = -1;
    for (; l <= r;)
    {
        long long mid;
        mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            result = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld\n", result);
    return 0;
}