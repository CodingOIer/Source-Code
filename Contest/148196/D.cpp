#include <cstdio>
const int MaxN = 1e6 + 5;
int n;
long long x;
long long xor_sum;
long long p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        xor_sum ^= p[i];
    }
    printf("%lld 0\n", xor_sum);
    return 0;
}