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
const int MaxN = 5e1 + 5;
int n;
int p[MaxN];
int s[MaxN];
bool cmp()
{
    for (int i = 1; i <= n; i++)
    {
        if (p[i] != s[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    memcpy(s, p, sizeof(p));
    std::sort(s + 1, s + 1 + n);
    if (cmp())
    {
        printf("YES\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                std::swap(p[i], p[j]);
                if (cmp())
                {
                    printf("YES\n");
                    return 0;
                }
                std::swap(p[i], p[j]);
            }
        }
        printf("NO\n");
    }
    return 0;
}