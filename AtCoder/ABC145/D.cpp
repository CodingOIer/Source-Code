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
const int MaxN = 1e6 + 5;
const int mod = 1e9 + 7;
int x, y;
int tx, ty;
int answer;
std::queue<std::pair<int, int>> queue;
int main()
{
    scanf("%d%d", &x, &y);
    queue.push(std::make_pair(0, 0));
    for (; !queue.empty();)
    {
        tx = queue.front().first;
        ty = queue.front().second;
        queue.pop();
        if (tx == x && ty == y)
        {
            answer++;
            if (answer >= mod)
            {
                answer %= mod;
            }
        }
        if (tx + 1 <= x && ty + 2 <= y)
        {
            queue.push(std::make_pair(tx + 1, ty + 2));
        }
        if (tx + 2 <= x && ty + 1 <= y)
        {
            queue.push(std::make_pair(tx + 2, ty + 1));
        }
    }
    printf("%d\n", answer);
    return 0;
}