#include <cmath>
#include <cstdio>
long long a, b;
long long answer;
long long judge(long long x)
{
    long long res = 0;
    for (; x != 0 && x % a == 0;)
    {
        x /= a;
        res++;
    }
    return res;
}
int main()
{
    scanf("%lld%lld", &a, &b);
    long long p = 1;
    for (long long i = 1; i <= b; i++)
    {
        p *= a;
    }
    long long all = 1;
    for (long long i = 1; i <= p; i++)
    {
        if (p % i == 0)
        {
            all *= i;
        }
    }
    printf("%lld\n", judge(all));
    return 0;
}
/*

*/