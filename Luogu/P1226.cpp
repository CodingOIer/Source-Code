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
ll answer;
ll a, b, p;
int main()
{
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=", a, b, p);
    answer = 1;
    for (; b != 0;)
    {
        if (b & 1)
        {
            answer = (answer * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    printf("%lld\n", answer);
    return 0;
}