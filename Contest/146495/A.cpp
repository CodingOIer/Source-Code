#include <cstdio>
long long a, b, n;
int main()
{
    scanf("%lld%lld%lld", &a, &b, &n);
    if (n * b <= a)
    {
        printf("%lld\n", n * b);
    }
    else
    {
        printf("%lld\n", a / b * b);
    }
    return 0;
}