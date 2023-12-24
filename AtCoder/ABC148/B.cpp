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
char s[MaxN], t[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%s %s", s, t);
    for (int i = 0; i < n; i++)
    {
        printf("%c%c", s[i], t[i]);
    }
    printf("\n");
    return 0;
}