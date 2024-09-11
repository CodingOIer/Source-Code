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
long long answer;
long long n;
int main()
{
    scanf("%lld", &n);
    answer = 0x3f3f3f3f3f3f3f3f;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            answer = std::min(answer, i + n / i - 2);
        }
    }
    printf("%lld\n", answer);
    return 0;
}