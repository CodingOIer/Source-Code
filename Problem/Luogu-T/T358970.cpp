/*
 * @Author: Redefinition
 * @Date: 2023-08-09 14:19:59
 * @LastEditors: Redefinition
 * @LastEditTime: 2023-08-09 14:36:01
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
int n;
int main()
{
    scanf("%d", &n);
    if (n == 2)
    {
        printf("1 2\n");
    }
    else if (n == 5)
    {
        printf("2 1 1 1 3\n");
    }
    else
    {
        for (int i = 1; 3 * i <= n; i++)
        {
            printf("%d 1 1 ", i + 1);
        }
        switch (n % 3)
        {
        case (1): {
            printf("%d\n", n / 3 + 2);
            break;
        }
        case (2): {
            printf("%d 1\n", n / 3 + 2);
            break;
        }
        }
        printf("\n");
    }
    return 0;
}