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
const int MaxN = 5e5 + 5;
int n, m;
int x, y;
int empty, bad;
int contest[MaxN];
std::map<int, int> how;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &contest[i]);
        how[contest[i]] = -1;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        how[x] = y;
    }
    for (int i = 1; i <= n; i++)
    {
        if (how[contest[i]] == -1)
        {
            empty++;
        }
        if (how[contest[i]] < 60)
        {
            bad++;
        }
    }
    printf("%d\n", empty);
    printf("%d\n", bad);
    return 0;
}