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
int x;
int n, m;
long long answer;
std::priority_queue<int> queue;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        queue.push(x);
    }
    for (int i = 1; i <= m; i++)
    {
        x = queue.top();
        queue.pop();
        x /= 2;
        queue.push(x);
    }
    for (; !queue.empty();)
    {
        x = queue.top();
        queue.pop();
        answer += x;
    }
    printf("%lld\n", answer);
    return 0;
}