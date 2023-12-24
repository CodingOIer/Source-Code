/*
 * @Author: Redefinition
 * @Date: 2023-08-09 15:50:08
 * @LastEditors: Redefinition
 * @LastEditTime: 2023-08-09 17:04:55
 */
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
const long long inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const long long MaxN = 1e7 + 5;
long long t;
long long t, p;
long long f[MaxN];
long long s[MaxN];
long long answer[MaxN];
int main()
{
    scanf("%lld", &t);
    f[1] = 1;
    f[2] = 1;
    for (long long i = 3; i <= 1e7; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) - ((f[i - 1] + f[i - 2]) / mod) * mod;
    }
    for (long long i = 1; i <= 1e7; i++)
    {
        s[i] = (s[i - 1] + (f[i] * f[i]) - ((f[i] * f[i]) / mod) * mod) -
               ((s[i - 1] + (f[i] * f[i]) - ((f[i] * f[i]) / mod) * mod) / mod) * mod;
    }
    for (long long i = 1; i <= 1e7; i++)
    {
        answer[i] = (answer[i - 1] +
                     (f[i] * ((s[std::max(0ll, i - 2)]) - ((s[std::max(0ll, i - 2)]) / mod) * mod + (f[i] * f[i]) -
                              ((f[i] * f[i]) / mod) * mod + f[i])) -
                     ((f[i] * ((s[std::max(0ll, i - 2)]) - ((s[std::max(0ll, i - 2)]) / mod) * mod + (f[i] * f[i]) -
                               ((f[i] * f[i]) / mod) * mod + f[i])) /
                      mod) *
                         mod) -
                    ((answer[i - 1] +
                      (f[i] * ((s[std::max(0ll, i - 2)]) - ((s[std::max(0ll, i - 2)]) / mod) * mod + (f[i] * f[i]) -
                               ((f[i] * f[i]) / mod) * mod + f[i])) -
                      ((f[i] * ((s[std::max(0ll, i - 2)]) - ((s[std::max(0ll, i - 2)]) / mod) * mod + (f[i] * f[i]) -
                                ((f[i] * f[i]) / mod) * mod + f[i])) /
                       mod) *
                          mod) /
                     mod) *
                        mod;
    }
    for (long long i = 1; i <= t; i++)
    {
        scanf("%lld%lld", &t, &p);
        if (p == 2)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n", answer[t] % mod);
        }
    }
    return 0;
}