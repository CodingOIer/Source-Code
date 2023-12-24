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
const int MaxN = 25;
int n;
int answer;
int m[MaxN];
int x[MaxN][MaxN];
int y[MaxN][MaxN];
bool good[MaxN];
void check()
{
    bool person[MaxN];
    memset(person, false, sizeof(person));
    for (int i = 1; i <= n; i++)
    {
        if (good[i])
        {
            person[i] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!good[i])
        {
            continue;
        }
        for (int j = 1; j <= m[i]; j++)
        {
            if (person[x[i][j]] != y[i][j])
            {
                return;
            }
            person[x[i][j]] = y[i][j];
        }
    }
    int res;
    res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (good[i])
        {
            res++;
        }
    }
    answer = std::max(answer, res);
}
void dfs(int x)
{
    if (x >= n + 1)
    {
        check();
    }
    else
    {
        good[x] = true;
        dfs(x + 1);
        good[x] = false;
        dfs(x + 1);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m[i]);
        for (int j = 1; j <= m[i]; j++)
        {
            scanf("%d%d", &x[i][j], &y[i][j]);
        }
    }
    dfs(1);
    printf("%d\n", answer);
    return 0;
}