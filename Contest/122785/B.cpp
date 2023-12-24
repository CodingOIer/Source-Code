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
long long x;
long long sum;
long long answer;
std::unordered_map<long long, long long> have;

int main()
{
    scanf("%lld", &n);
    have[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &x);
        sum ^= x;
        if (have.find(sum) != have.end())
        {
            answer += have[sum];
        }
        have[sum]++;
    }
    printf("%lld\n", answer);
    return 0;
}
