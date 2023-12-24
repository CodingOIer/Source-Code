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
int t;
int n, m;
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        if (i % 2 == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    for (int i = 2; i <= n - 2; i++)
    {
        if (i % 2 == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        for (int j = 1; j <= m - 2; j++)
        {
            printf("0");
        }
        if (i % 2 == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        printf("\n");
    }
    for (int j = 1; j <= m; j++)
    {
        printf("0");
    }
    printf("\n");
    for (int i = 1; i <= m; i++)
    {
        if (i % 2 == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    printf("\n");
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}