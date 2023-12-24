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
long long n;
long long five;
int main()
{
    scanf("%lld", &n);
    if (n % 2 == 1)
    {
        printf("0\n");
        return 0;
    }
    five += n / 10;
    n /= 10;
    for (;;)
    {
        if (n == 0)
        {
            break;
        }
        five += n / 5;
        n /= 5;
    }
    printf("%lld\n", five);
    return 0;
}