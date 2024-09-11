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
const int MaxN = 15;
int n;
int need1;
int need2;
int p1[MaxN];
int p2[MaxN];
int to[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p1[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p2[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        to[i] = i;
    }
    for (;;)
    {
        if (memcmp(p1, to, sizeof(to)) == 0)
        {
            break;
        }
        need1++;
        std::next_permutation(to + 1, to + 1 + n);
    }
    for (int i = 1; i <= n; i++)
    {
        to[i] = i;
    }
    for (;;)
    {
        if (memcmp(p2, to, sizeof(to)) == 0)
        {
            break;
        }
        need2++;
        std::next_permutation(to + 1, to + 1 + n);
    }
    printf("%d\n", std::abs(need1 - need2));
    return 0;
}