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
int a, b, c, d;
int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a + b + c + d < 100)
    {
        printf("Gray\n");
    }
    else if (a + b + c + d < 120)
    {
        printf("Blue\n");
    }
    else if (a + b + c + d < 170)
    {
        printf("Green\n");
    }
    else if (a + b + c + d < 230)
    {
        printf("Orange\n");
    }
    else if (a + b + c + d < 500)
    {
        printf("Red\n");
    }
    return 0;
}