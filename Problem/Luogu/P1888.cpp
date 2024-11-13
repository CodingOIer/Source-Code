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
long long a, b, c;
long long min, max;
int main()
{
    scanf("%lld%lld%lld", &a, &b, &c);
    min = std::min({a, b, c});
    max = std::max({a, b, c});
    printf("%lld/%lld\n", min / std::__gcd(min, max), max / std::__gcd(min, max));
    return 0;
}