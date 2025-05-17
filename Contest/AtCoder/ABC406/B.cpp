#include <cmath>
#include <cstdio>
int n;
long long k;
long long answer;
int main()
{
    scanf("%d%lld", &n, &k);
    k = std::pow(10, k);
    answer = 1;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        scanf("%lld", &x);
        __int128 c = answer;
        c *= x;
        if (c >= k)
        {
            answer = 1;
        }
        else
        {
            answer *= x;
        }
    }
    printf("%lld\n", answer);
    return 0;
}