#include <cstdio>
#include <ctime>
#include <random>
const int MaxN = 5e5 + 5;
long long op;
long long all;
long long now;
long long u, v;
long long n, m, q;
long long in[MaxN];
long long before[MaxN];
long long value[MaxN];
std::mt19937 my_rand(time(0));
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        value[i] = my_rand();
        all += value[i];
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld", &u, &v);
        in[v] += value[u];
        before[v] = in[v];
        now += value[u];
    }
    scanf("%lld", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld", &op);
        if (op == 1)
        {
            scanf("%lld%lld", &u, &v);
            in[v] -= value[u];
            now -= value[u];
        }
        else if (op == 2)
        {
            scanf("%lld", &u);
            now -= in[u];
            in[u] = 0;
        }
        else if (op == 3)
        {
            scanf("%lld%lld", &u, &v);
            in[v] += value[u];
            now += value[u];
        }
        else if (op == 4)
        {
            scanf("%lld", &u);
            now += before[u] - in[u];
            in[u] = before[u];
        }
        printf("%s\n", now == all ? "YES" : "NO");
    }
    return 0;
}