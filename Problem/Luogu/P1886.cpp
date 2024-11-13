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
const int MaxN = 1e6 + 5;
int n, k;
int x, index;
int max[MaxN];
int min[MaxN];
std::priority_queue<std::pair<int, int>> queue_max;
std::priority_queue<std::pair<int, int>> queue_min;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &x);
        queue_max.push({x, i});
        queue_min.push({-x, i});
    }
    for (int i = 1; i <= n - k; i++)
    {
    }
    return 0;
}