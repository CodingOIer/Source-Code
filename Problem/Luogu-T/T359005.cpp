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
int sum;
int len;
int l, r;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%d%d", &l, &r);
    if (n == 1)
    {
        printf("%d %d\n", 2 * l, 2 * l + 1);
        printf("%d\n", (2 * l) ^ (2 * l + 1));
    }
    else if (n == 2)
    {
        len = 2 * r - 2 * l + 2;
        sum = 2 * (l + r) + 1;
        for (int i = 2 * r + 1, w = 1; i >= 2 * l; i -= 2, w += 2)
        {
            p[w] = i;
            p[w + 1] = sum - i;
        }
        for (int i = 1; i <= len; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
        printf("%d\n", ((2 * l + len / 2) ^ (2 * l + len / 2 - 1)));
    }
    else if (n == 3)
    {
    }
    return 0;
}
/*
7 2 5 4 1 3
*/