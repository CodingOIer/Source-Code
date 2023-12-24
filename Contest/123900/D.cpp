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
const int MaxN = 1e2 + 5;

long long n, m;
long long p[MaxN];
long long f[MaxN];
long long ls[MaxN];
long long rs[MaxN];
long long add[MaxN];
long long left[MaxN];
long long want[MaxN];
long long right[MaxN];

bool check(long long k)
{
    for (int i = 1; i <= n; i++)
    {
        long long happy;
        happy = 0;
        if (f[i])
        {
            happy += k;
            happy += std::max(0ll, (k * (ls[i] - 1 - ls[std::max(0ll, i - k)]) -
                                    (left[i] - left[std::max(0ll, i - k)] - (k - 1) * ls[i]))) +
                     std::max(0ll, (k * (rs[i] - 1 - rs[std::min(n, i + k)]) -
                                    (right[i] - right[std::min(n, i + k)] + (k - 1) * rs[i])));
        }
        else
        {
            happy += std::max(0ll, (k * (ls[i] - ls[std::max(0ll, i - k)]) -
                                    (left[i] - left[std::max(0ll, i - k)] - (k - 1) * ls[i]))) +
                     std::max(0ll, (k * (rs[i] - rs[std::min(n, i + k)]) -
                                    (right[i] - right[std::min(n, i + k)] + (k - 1) * rs[i])));
        }
        if (happy < want[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &want[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &p[i]);
        f[p[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        ls[i] = ls[i - 1] + f[i];
    }
    for (int i = n; i >= 1; i--)
    {
        rs[i] = rs[i + 1] + f[i];
    }
    for (int i = 1; i <= n; i++)
    {
        left[i] = left[i - 1] + add[i - 1];
        add[i] += add[i - 1] + f[i];
    }
    memset(add, 0, sizeof(add));
    for (int i = n; i >= 1; i--)
    {
        right[i] = right[i + 1] + add[i + 1];
        add[i] += add[i + 1] + f[i];
    }
    long long l, r;
    long long res;
    res = -1;
    l = 1;
    r = 1e12;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld\n", res);
    return 0;
}