#include <cstdio>
const int MaxN = 5e6 + 5;
long long n, mod, k;
long long a[MaxN];
long long s[MaxN];
long long p[MaxN];
int main()
{
    scanf("%lld%lld%lld", &n, &mod, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    s[n] = a[n];
    for (int i = n - 1; i >= 1; i++)
    {
        s[i] = s[i + 1] * a[i];
    }
    return 0;
}