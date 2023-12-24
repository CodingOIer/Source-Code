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
const int MaxN = 5e3 + 5;
const int MaxM = 2e5 + 5;
struct str
{
    int x, y;
    int len;
};
int n, m;
int answer;
int f[MaxN];
str link[MaxM];
int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &link[i].x, &link[i].y, &link[i].len);
    }
    std::sort(link + 1, link + 1 + m, [](str a, str b) { return a.len < b.len; });
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        if (find(link[i].x) != find(link[i].y))
        {
            answer += link[i].len;
            f[find(link[i].x)] = find(link[i].y);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (find(i) != find(i - 1))
        {
            printf("orz\n");
            return 0;
        }
    }
    printf("%d\n", answer);
    return 0;
}