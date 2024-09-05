#include <cstdio>
#include <random>
constexpr int MaxN = 2e5 + 5;
int n;
long long a[MaxN];
long long b[MaxN];
long long c[MaxN];
std::mt19937 rnd(std::random_device{}());
bool check(long long x)
{
    for (int i = 1; i <= n; i++)
    {
        if (x * x * x + a[i] * x * x + b[i] * x + c[i] == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    }
    for (;;)
    {
        long long w = rnd() % int(1e6 + 1);
        if (check(w))
        {
            printf("%lld\n", w);
            break;
        }
    }
    return 0;
}