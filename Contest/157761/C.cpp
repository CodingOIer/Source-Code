#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 3e5 + 5;
int t;
char s[MaxN];
char l[MaxN];
long long n, k;
long long p[MaxN];
std::vector<std::pair<long long, long long>> answer;
inline int getLen(long long x)
{
    int res = 0;
    for (; x > 0;)
    {
        res++;
        x /= 10;
    }
    return res;
}
inline void add(char *a, char *b)
{
    long long x, y;
    x = 0;
    y = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        x = x * 10 + a[i] - '0';
    }
    for (int i = 0; b[i] != '\0'; i++)
    {
        y = y * 10 + b[i] - '0';
    }
    if (x > n)
    {
        return;
    }
    if (y > p[n])
    {
        return;
    }
    answer.push_back({x, y});
}
inline void get(long long x)
{
    if (x < 10)
    {
        return;
    }
    long long len = getLen(x);
    sprintf(l, "%lld", x);
    long long w = 0;
    for (; w < len - 1;)
    {
        s[w] = l[w];
        s[w + 1] = '\0';
        w++;
        if (s[0] != '0' && l[w] != '0')
        {
            add(s, l + w);
        }
    }
}
inline void solve()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    if (k == 1)
    {
        printf("0\n");
        return;
    }
    answer.clear();
    long long now = k;
    for (; now <= 1e15; now *= k)
    {
        get(now);
    }
    std::sort(answer.begin(), answer.end());
    printf("%llu\n", answer.size());
    for (auto x : answer)
    {
        printf("%lld %lld\n", x.first, x.second);
    }
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}