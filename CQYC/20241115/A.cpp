#include <cstdio>
#include <cstdlib>
constexpr int MaxN = 1e6 + 5;
int n;
int p[MaxN];
int w[MaxN];
int b[MaxN];
int c[MaxN];
int k[MaxN];
long long tree[MaxN];
inline void change(int x, int val)
{
    for (; x <= n; x += x & -x)
    {
        tree[x] += val;
    }
}
inline int query(int x)
{
    long long res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
inline int query(int l, int r)
{
    return query(r) - query(l - 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        w[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (w[i] < w[i + 1] || i == n)
        {
            b[i] = i;
        }
        else
        {
            b[i] = i + 1;
            b[i + 1] = i;
            i++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        c[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        k[w[i]] = c[i];
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer += query(k[i] + 1, n);
        change(k[i], 1);
    }
    printf("%lld\n", answer);
    return 0;
}
