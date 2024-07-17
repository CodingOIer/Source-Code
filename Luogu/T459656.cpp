#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
int p[MaxN];
long long f[MaxN];
long long tree[MaxN];
inline void change(int x, int v)
{
    for (; x <= n; x += x & -x)
    {
        tree[x] += v;
    }
}
inline int query(int x)
{
    int r = 0;
    for (; x > 0; x -= x & -x)
    {
        r += tree[x];
    }
    return r;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        p[i]++;
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        f[p[i]] += i - query(p[i]) - 1;
        change(p[i], 1);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", answer);
        answer += f[i];
    }
    return 0;
}