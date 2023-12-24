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
const int MaxN = 2e5 + 5;
int n;
int x;
int answer;
int c[MaxN];
bool read[MaxN];
std::vector<int> p[MaxN];
void dfs(int x)
{
    if (read[x])
    {
        return;
    }
    if (c[x] == 0)
    {
        read[x] = true;
        if (x != 1)
        {
            printf("%d ", x);
        }
    }
    else
    {
        for (int i = 1; i <= c[x]; i++)
        {
            dfs(p[x][i]);
        }
        read[x] = true;
        if (x != 1)
        {
            printf("%d ", x);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        p[i].push_back(0);
        for (int j = 1; j <= c[i]; j++)
        {
            scanf("%d", &x);
            p[i].push_back(x);
        }
    }
    dfs(1);
    printf("\n");
    return 0;
}