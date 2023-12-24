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
int n;
int l, r;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    l = -1;
    r = -inf;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        if (p[i] == 1)
        {
            if (l == -1)
            {
                l = i;
            }
            r = std::max(r, i);
        }
    }
    printf("%d\n", l == -1 ? 0 : (r - l + 1));
    return 0;
}