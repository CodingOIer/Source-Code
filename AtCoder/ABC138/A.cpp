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
const int MaxN = 1e5 + 5;
int a;
char l[MaxN];
int main()
{
    scanf("%d", &a);
    getchar();
    scanf("%s", l);
    if (a < 3200)
    {
        printf("red\n");
    }
    else
    {
        printf("%s\n", l);
    }
    return 0;
}