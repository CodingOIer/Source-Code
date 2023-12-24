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
    ll x, y;
};
ll cnt;
ll t, m;
ll x, y;
ll answer;
str p[MaxN];
std::priority_queue<std::pair<ll, ll>> queue;
int main()
{
    scanf("%lld%lld", &t, &m);
    for (int i = 1; i <= t; i++)
    {
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }
    std::sort(p + 1, p + 1 + t, [](str a, str b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
    for (int i = 1; i <= m; i++)
    {
        for (; cnt <= t && i + p[cnt].x - 1 <= m;)
        {
            queue.push(p[i].y);
        }
    }
    printf("%lld\n", answer);
    return 0;
}