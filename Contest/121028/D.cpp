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
const long long MaxN = 1e6 + 5;
long long how;
long long max;
long long n, c;
long long answer;
long long p[MaxN];
int main()
{
    scanf("%lld%lld", &n, &c);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    answer = inf;
    for (long long k = 0; k <= n; k++)
    {
        max = std::max(max, p[k]);
        if (max + c * (n - k) < answer)
        {
            how = k;
        }
        answer = std::min(answer, max + c * (n - k));
    }
    printf("%lld %lld\n", how, answer);
    return 0;
}