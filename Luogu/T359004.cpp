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
long long n, t, f;
long long answer;
long long x, a;
int main()
{
    scanf("%lld%lld%lld", &n, &t, &f);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x, &a);
        a -= t - f;
        if (a <= x)
        {
            answer++;
        }
    }
    printf("%lld\n", answer);
    return 0;
}