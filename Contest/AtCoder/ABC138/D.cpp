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
int n, q;
int x, y;
int answer[MaxN];
std::vector<int> link[MaxN];
void dfs(int x, int ans)
{
    answer[x] += ans;
    for (int i = 0; i < link[x].size(); i++)
    {
        dfs(link[x][i], answer[x]);
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        link[x].push_back(y);
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &x, &y);
        answer[x] += y;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}