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
const long long mod = 998244353;
long long t;
long long op;
long long n, m;
long long want;
int main()
{
    scanf("%lld", &t);
    for (long long i = 1; i <= t; i++)
    {
        scanf("%lld", &op);
        if (op == 1)
        {
            scanf("%lld%lld", &n, &m);
            printf("%lld\n", n + m - 1);
        }
        else if (op == 2)
        {
            scanf("%lld%lld%lld", &n, &m, &want);
            if (n > m)
            {
                std::swap(n, m);
            }
            n %= mod;
            m %= mod;
            want %= mod;
            long long diff = (want - n + 1 + mod) % mod;
            long long result = ((n * diff + mod) % mod - (n * m + mod) % mod + mod) % mod;
            printf("%lld\n", result);
        }
    }
    return 0;
}
/*
n'+m'-1=q
m'=q-n'+1
*/