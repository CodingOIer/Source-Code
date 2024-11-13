#include <bits/stdc++.h>
using namespace std;
long long t;
long long cycle;
int main()
{
    scanf("%lld", &t);
    for (long long i = 1; i <= t; i++)
    {
        long long t, k;
        scanf("%lld%lld", &t, &k);
        if (t % 2 == 0)
        {
            printf("%lld\n", (k - 1) % t + 1);
        }
        else
        {
            cycle = (t - 1) / 2;
            printf("%lld\n", ((k + (k - 1) / cycle) - 1) % t + 1);
        }
    }
    return 0;
}