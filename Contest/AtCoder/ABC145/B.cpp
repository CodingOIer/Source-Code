/*
 * @Author: Redefinition
 * @Date: 2023-08-10 08:28:07
 * @LastEditors: Redefinition
 * @LastEditTime: 2023-08-10 08:42:34
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
const int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%d", &n);
    getchar();
    scanf("%s", s);
    if (n % 2 == 1)
    {
        printf("No\n");
    }
    else
    {
        for (int i = 0, j = n / 2; i < n / 2; i++, j++)
        {
            if (s[i] != s[j])
            {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
    }
    return 0;
}