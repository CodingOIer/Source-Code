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
long long a, b, x;
int how(int a)
{
    int b = 0;
    while (a)
    {
        a /= 10;
        b++;
    }
    return b;
}
int main()
{
    scanf("%lld%lld%lld", &a, &b, &x);
    long long l, r;
    long long res;
    l = 0, r = 1e9;
    for (; l <= r;)
    {
        long long mid;
        mid = (l + r) / 2;
        if (a * mid + how(mid) * b <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld\n", res);
    return 0;
}
