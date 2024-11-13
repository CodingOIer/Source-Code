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
const int MaxN = 3e6 + 5;
int n;
int p[MaxN];
int answer[MaxN];
std::stack<int> stack;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        for (;;)
        {
            if (stack.empty() || p[stack.top()] > p[i])
            {
                break;
            }
            stack.pop();
        }
        if (stack.empty())
        {
            answer[i] = 0;
        }
        else
        {
            answer[i] = stack.top();
        }
        stack.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}