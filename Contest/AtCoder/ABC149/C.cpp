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
int x;
int f[MaxN];
void init()
{
    f[1] = 1;
    for (int i = 2; i <= 2e5; i++)
    {
        if (f[i] == 1)
        {
            continue;
        }
        for (int j = 2; i * j <= 2e5; j++)
        {
            f[i * j] = 1;
        }
    }
}
int main()
{
    init();
    scanf("%d", &x);
    for (int i = x;; i++)
    {
        if (f[i] == 0)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}