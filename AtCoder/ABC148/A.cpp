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
int a, b;
int main()
{
    scanf("%d%d", &a, &b);
    if (a != 1 && b != 1)
    {
        printf("1\n");
    }
    else if (a != 2 && b != 2)
    {
        printf("2\n");
    }
    else if (a != 3 && b != 3)
    {
        printf("3\n");
    }
    return 0;
}