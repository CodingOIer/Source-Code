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
ll t;
ll t, p;
ll answer;
ll answer1, answer2, answer3, answer4, answer5, answer6, answer7, answer8;
int main()
{
    scanf("%lld", &t);
    for (int u = 1; u <= t; u++)
    {
        scanf("%d%d", &t, &p);
        const __uint128_t brt = ((__uint128_t)1 << 64) / p;
        ll i;
        for (i = 1; i + 8 <= t; i += 8)
        {
            answer1 *= i;
            answer2 *= (i + 1);
            answer3 *= (i + 2);
            answer4 *= (i + 3);
            answer5 *= (i + 4);
            answer6 *= (i + 5);
            answer7 *= (i + 6);
            answer8 *= (i + 7);
            answer1 = answer1 - p * (brt * answer1 >> 64);
            answer2 = answer2 - p * (brt * answer2 >> 64);
            answer3 = answer3 - p * (brt * answer3 >> 64);
            answer4 = answer4 - p * (brt * answer4 >> 64);
            answer5 = answer5 - p * (brt * answer5 >> 64);
            answer6 = answer6 - p * (brt * answer6 >> 64);
            answer7 = answer7 - p * (brt * answer7 >> 64);
            answer8 = answer8 - p * (brt * answer8 >> 64);
            if (answer1 >= p)
            {
                answer1 -= p;
            }
            if (answer2 >= p)
            {
                answer2 -= p;
            }
            if (answer3 >= p)
            {
                answer3 -= p;
            }
            if (answer4 >= p)
            {
                answer4 -= p;
            }
            if (answer5 >= p)
            {
                answer5 -= p;
            }
            if (answer6 >= p)
            {
                answer6 -= p;
            }
            if (answer7 >= p)
            {
                answer7 -= p;
            }
            if (answer8 >= p)
            {
                answer8 -= p;
            }
        }
        answer1 = answer1 * answer2 % p;
        answer3 = answer3 * answer4 % p;
        answer5 = answer5 * answer6 % p;
        answer7 = answer7 * answer8 % p;
        answer1 = answer1 * answer3 % p;
        answer5 = answer5 * answer7 % p;
        answer = answer1 * answer5 % p;
        for (; i <= t; i++)
        {
            answer = answer * i % p;
        }
        printf("%lld\n", answer);
    }
    return 0;
}