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
const int MaxN = 1e4 + 5;
int n;
int len;
char s[MaxN];
int main()
{
    scanf("%d", &n);
    getchar();
    scanf("%s", s);
    len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        s[i] = 'A' + (s[i] - 'A' + n) % 26;
    }
    printf("%s\n", s);
    return 0;
}