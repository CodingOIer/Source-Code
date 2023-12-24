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
const int MaxN = 2e5 + 5;
long long n, k;
long long answer;
long long r, s, p;
char robot[MaxN];
int main()
{
    scanf("%lld%lld", &n, &k);
    scanf("%lld%lld%lld", &r, &s, &p);
    scanf("%s", (robot + 1));
    for (long long i = 1; i <= n; i++)
    {
        if (robot[i] == 'r')
        {
            answer += p;
        }
        if (robot[i] == 's')
        {
            answer += r;
        }
        if (robot[i] == 'p')
        {
            answer += s;
        }
        if (robot[i + k] == robot[i])
        {
            robot[i + k] = '\0';
        }
    }
    printf("%lld\n", answer);
    return 0;
}