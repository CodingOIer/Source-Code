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
int x;
int main()
{
    scanf("%d", &x);
    for (int i = 1; i <= 9; i++)
    {
        if (x % i == 0 && x / i <= 9)
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}