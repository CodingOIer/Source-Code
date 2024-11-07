#include <cstdio>
long long n;
int main()
{
    scanf("%lld", &n);
    printf("%lld\n", (n % 998244353 + 998244353) % 998244353);
    return 0;
}