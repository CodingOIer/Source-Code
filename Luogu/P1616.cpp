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
const int MaxN = 1e4 + 5;
long long m, t;
long long v[MaxN];
long long val[MaxN];
long long dp[2][MaxN];
int main()
{
    scanf("%lld%lld", &m, &t);
    for (long long i = 1; i <= m; i++)
    {
        scanf("%lld%lld", &v[i], &val[i]);
    }
    for (long long i = 1; i <= m; i++)
    {
    }
    return 0;
}