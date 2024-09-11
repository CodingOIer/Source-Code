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
#define debug printf("Debug\a")
typedef long long ll;
const int inf = 0x3f3f3f3f;
long long a, b;
long long answer;
bool prime(long long x)
{
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%lld%lld", &a, &b);
    if (a > b)
    {
        std::swap(a, b);
    }
    if (a == 1)
    {
        printf("1\n");
    }
    else
    {
        for (long long i = 1; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                if (b - (b / i) * i == 0 && prime(i))
                {
                    answer++;
                }
                if (b - (b / (a / i)) * (a / i) == 0 && prime(a / i))
                {
                    answer++;
                }
                if (a % b == 0)
                {
                    answer++;
                }
            }
        }
        printf("%lld\n", answer);
    }
    return 0;
}