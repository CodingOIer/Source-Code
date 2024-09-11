#include <bits/stdc++.h>
using namespace std;
const long long MaxN = 1e5 + 5;
long long t, k;
long long to;
long long answer;
long long p[MaxN];
long long sum[MaxN];
int main()
{
    scanf("%lld%lld", &t, &k);
    for (long long i = 1; i <= t; i++)
    {
        scanf("%lld", &p[i]);
        sum[i] = sum[i - 1] + p[i];
    }
    for (long long i = 1; i <= t; i++)
    {
        for (; sum[to] - sum[i - 1] < k && to <= t;)
        {
            to++;
        }
        answer += t - to + 1;
    }
    printf("%lld\n", answer);
    return 0;
}