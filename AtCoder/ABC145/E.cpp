/*
 * @Author: Redefinition
 * @Date: 2023-08-10 08:28:20
 * @LastEditors: Redefinition
 * @LastEditTime: 2023-08-10 09:17:06
 */
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
const int MaxN = 3e3 + 5;
int n, t;
int v[MaxN];
int val[MaxN];
int dp[2][MaxN];
bool f[2][MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[i], &val[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(f[i % 2], 0, sizeof(0));
        for (int j = 1; j <= t; j++)
        {
            if (j >= v[i])
            {
                dp[i % 2][j] = std::max(dp[!(i % 2)][j], dp[!(i % 2)][j - v[i]] + val[i]);
                if (dp[!(i % 2)][j] >= dp[!(i % 2)][j - v[i]] + val[i])
                {
                    dp[i % 2][j] = dp[!(i % 2)][j];
                }
                else
                {
                }
            }
        }
    }
    return 0;
}