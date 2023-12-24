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
long long a, b, k;
int main()
{
    scanf("%lld%lld%lld", &a, &b, &k);
    printf("%lld %lld\n", std::max(0ll, a - k), std::max(0ll, b - std::max(0ll, k - a)));
    return 0;
}