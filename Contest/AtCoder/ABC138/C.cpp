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
const int MaxN = 5e1 + 5;
int n;
double p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n - 1; i++)
    {
        p[i] = (double(p[i]) + double(p[i + 1])) / 2.0;
        p[i + 1] = p[i];
    }
    printf("%.8f\n", p[n]);
    return 0;
}