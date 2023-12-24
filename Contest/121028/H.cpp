#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define debug printf("Debug\n")
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int MaxN = 1e6 + 5;
long long t;
long long sum;
long long n, k;
long long p[MaxN];
inline void solve()
{
    scanf("%lld%lld", &n, &k);
    sum = 0;
    for (register int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        sum += p[i];
    }
    if (sum >= k)
    {
        printf("Yes\n");
        return;
    }
    for (register int i = 1; i <= n; i++)
    {
        for (register int j = i + 1; j <= n; j++)
        {
            if ((p[i] * p[j] - ((p[i] * p[j]) / 154) * 154) == 0 || (p[i] * p[j] - ((p[i] * p[j]) / 147) * 147) == 0)
            {
                printf("Yes\n");
                return;
            }
        }
    }
    printf("No\n");
    return;
}
int main()
{
    scanf("%lld", &t);
    for (register int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}