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
int x, y;
int u, v;
int answer;
int len_x[MaxN];
int len_y[MaxN];

std::vector<int> link[MaxN];

void dfs_x(int x)
{
    for (int i = 0; i < link[x].size(); i++)
    {
        if (len_x[x] + 1 < len_x[link[x][i]])
        {
            len_x[link[x][i]] = len_x[x] + 1;
            dfs_x(link[x][i]);
        }
    }
}

void dfs_y(int x)
{
    for (int i = 0; i < link[x].size(); i++)
    {
        if (len_y[x] + 1 < len_y[link[x][i]])
        {
            len_y[link[x][i]] = len_y[x] + 1;
            dfs_y(link[x][i]);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    memset(len_x, 0x3f, sizeof(len_x));
    memset(len_y, 0x3f, sizeof(len_y));
    len_x[u] = 0;
    len_y[v] = 0;
    dfs_x(u);
    dfs_y(v);
    for (int i = 1; i <= n; i++)
    {
        // printf("%d %d\n", len_x[i], len_y[i]);
        answer = std::max(answer, len_y[i] + (len_y[i] - len_x[i]) / 2 - 1);
    }
    printf("%d\n", answer);
    return 0;
}