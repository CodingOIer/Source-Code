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
const int MaxN = 2e1 + 5;

long long t;
long long n, x;
long long p[MaxN];
long long s[MaxN];

void solve()
{
    scanf("%lld%lld", &n, &x);
    if (n == 2)
    {
        printf("%lld\n", x);
        return;
    }
    for (long long i = 1; i <= n - 2; i++)
    {
        if (x % 2 != 0)
        {
            break;
        }
        x /= 2;
    }
    for (long long i = 1; i <= n - 2; i++)
    {
        x *= 2;
    }
    printf("%lld\n", x);
    return;
}

int main()
{
    scanf("%lld", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}