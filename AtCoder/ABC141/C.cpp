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
int n, k, q;
int p[MaxN];
int sum[MaxN];
int main()
{
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &x);
        p[x]++;
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (k > sum[i - 1] + (sum[n] - sum[i]))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}