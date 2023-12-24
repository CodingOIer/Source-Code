#include <cstdio>
long long a, b, n;
int main()
{
    scanf("%lld%lld%lld", &a, &b, &n);
    printf("%lld\n", (a + (a + (n - 1) * (b - a))) * n / 2);
    return 0;
}