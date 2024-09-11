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
const int MaxN = 25;
int n;
int answer;
int a[MaxN];
int b[MaxN];
int c[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        answer += b[a[i]];
        if (a[i] - 1 == a[i - 1])
        {
            answer += c[a[i - 1]];
        }
    }
    printf("%d\n", answer);
    return 0;
}