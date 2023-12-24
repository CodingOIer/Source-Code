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
const int MaxM = 2e5 + 5;
int n, m, s;
int x, y, len;
bool vis[MaxN];
int answer[MaxN];
std::vector<int> link[MaxN];
std::vector<int> length[MaxN];
void Dijkstra()
{
    std::priority_queue<std::pair<int, int>> queue;
    for (int i = 1; i <= n; i++)
    {
        answer[i] = 2147483647;
    }
    answer[s] = 0;
    queue.push({0, s});
    for (; !queue.empty();)
    {
        int x;
        x = queue.top().second;
        queue.pop();
        if (vis[x])
        {
            continue;
        }
        vis[x] = true;
        for (int i = 0; i < (int)(link[x].size()); i++)
        {
            if (answer[link[x][i]] > answer[x] + length[x][i])
            {
                answer[link[x][i]] = answer[x] + length[x][i];
                queue.push({-answer[link[x][i]], link[x][i]});
            }
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &len);
        link[x].push_back(y);
        length[x].push_back(len);
    }
    Dijkstra();
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}