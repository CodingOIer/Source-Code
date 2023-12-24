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
const int MaxN = 1e5 + 5;
long long n, ti;
long long output;
long long p[MaxN];
long long t[MaxN];
long long answer[MaxN];
int main()
{
    scanf("%lld%lld", &n, &ti);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &p[i], &t[i]);
    }
    for (long long i = 1; i <= n; i++)
    {
        answer[i] = std::max(0ll, ti - t[i] + 1) * p[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        if (answer[i] > answer[output])
        {
            output = i;
        }
    }
    printf("%lld\n", output);
    return 0;
}