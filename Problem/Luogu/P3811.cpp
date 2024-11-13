#include <cstdio>
const int MaxN = 3e6 + 5;
long long n, p;
long long answer[MaxN];
int main()
{
    scanf("%lld%lld", &n, &p);
    answer[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        answer[i] = ((p - p / i) * answer[p % i]) % p;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}