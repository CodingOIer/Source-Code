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
const int MaxN = 1e2 + 5;
int n;
int answer;
int a[MaxN];
int b[MaxN];
int main()
{
    scanf("%d", &n);
    memset(a, 0x3f, sizeof(a));
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &b[i]);
        a[i] = std::min(a[i], b[i]);
        a[i + 1] = std::min(a[i + 1], b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        answer += a[i];
    }
    printf("%d\n", answer);
    return 0;
}