#include <algorithm>
#include <cstdio>
const int MaxN = 1e6 + 5;
long long n, m;
long long w, l, r;
long long p[4 * MaxN];
long long d[4 * MaxN];
long long b[4 * MaxN];
void build(long long s, long long t, long long k)
{
    if (s == t)
    {
        d[k] = p[s];
        return;
    }
    long long mid;
    mid = (s + t) / 2;
    build(s, mid, 2 * k);
    build(mid + 1, t, 2 * k + 1);
    d[k] = std::min(d[2 * k], d[2 * k + 1]);
}
void push_down(long long s, long long t, long long k)
{
    if (b[k] != 0)
    {
        d[2 * k];
    }
}
long long min()
{
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    return 0;
}