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
int n;
int two;
int first;
int second;
int p[MaxN];
int s[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        s[i] = p[i];
    }
    std::sort(s + 1, s + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == s[n])
        {
            printf("%d\n", s[n - 1]);
        }
        else
        {
            printf("%d\n", s[n]);
        }
    }
    return 0;
}