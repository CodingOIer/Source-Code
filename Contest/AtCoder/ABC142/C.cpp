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
class str
{
  public:
    int x, id;
};
int n;
str p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i].x);
        p[i].id = i;
    }
    std::sort(p + 1, p + 1 + n, [](str a, str b) { return a.x < b.x; });
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", p[i].id);
    }
    printf("\n");
    return 0;
}