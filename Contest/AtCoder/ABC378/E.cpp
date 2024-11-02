#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, m;
int p[MaxN];
long long tree[2][MaxN];
void change(int type, int x, long long val)
{
    for (; x <= m; x += x & -x)
    {
        tree[type][x] += val;
    }
}
long long query(int type, int x)
{
    long long res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[type][x];
    }
    return res;
}
long long query(int type, int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    return query(type, r + 1) - query(type, l);
}
int main()
{
    scanf("%d%d", &n, &m);
    long long sum = 0;
    long long answer = 0;
    change(0, 1, 0);
    change(1, 1, 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        sum += p[i];
        sum %= m;
        answer += (query(1, 0, sum - 1) * sum - query(0, 0, sum - 1)) +
                  (query(1, sum + 1, m - 1) * (m + sum) - query(0, sum + 1, m - 1));
        change(0, sum + 1, sum);
        change(1, sum + 1, 1);
    }
    printf("%lld\n", answer);
    return 0;
}