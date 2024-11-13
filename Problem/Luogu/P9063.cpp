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
int t;
ll x;
int main()
{
    scanf("%d", &t);
    for (register int i = 1; i <= t; i++)
    {
        scanf("%lld", &x);
        printf("%s\n", x & 1 ? "Yes" : "No");
    }
    return 0;
}