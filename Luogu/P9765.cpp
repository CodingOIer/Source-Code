#include <cstdio>
long long d, m, w;
long long i, j, k;
int main()
{
    scanf("%lld%lld%lld", &d, &m, &w);
    scanf("%lld%lld%lld", &i, &j, &k);
    k--;
    j--;
    i--;
    long long day = k * m * d + j * d + i;
    day %= w;
    printf("%c\n", (char)('a' + day));
    return 0;
}