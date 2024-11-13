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
const int MaxN = 1e4 + 5;
int n, m;
int f[MaxN];
int op, x, y;
int find(int x)
{
    if (f[x] == x)
    {
        return x;
    }
    else
    {
        f[x] = find(f[x]);
        return f[x];
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            if (find(x) != find(y))
            {
                f[find(x)] = find(y);
            }
        }
        else if (op == 2)
        {
            printf("%s\n", find(x) == find(y) ? "Y" : "N");
        }
    }

    return 0;
}