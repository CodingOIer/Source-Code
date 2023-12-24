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
int n;
int op, x;
std::priority_queue<int> p;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            p.push(-x);
        }
        else if (op == 2)
        {
            printf("%d\n", -p.top());
        }
        else if (op == 3)
        {
            p.pop();
        }
    }
    return 0;
}