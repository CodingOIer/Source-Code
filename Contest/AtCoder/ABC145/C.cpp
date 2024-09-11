/*
 * @Author: Redefinition
 * @Date: 2023-08-10 08:28:11
 * @LastEditors: Redefinition
 * @LastEditTime: 2023-08-10 08:58:56
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
const int MaxN = 15;
int n;
int x[MaxN];
int y[MaxN];
int p[MaxN];
double answer;
double dis(int x_1, int y_1, int x_2, int y_2)
{
    return sqrt(double(x_1 - x_2) * double(x_1 - x_2) + double(y_1 - y_2) * double(y_1 - y_2));
}
void Get()
{
    for (int i = 2; i <= n; i++)
    {
        answer += dis(x[p[i - 1]], y[p[i - 1]], x[p[i]], y[p[i]]);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        p[i] = i;
    }
    for (;;)
    {
        Get();
        if (!std::next_permutation(p + 1, p + 1 + n))
        {
            break;
        }
    }
    for (double i = 1; i <= n; i++)
    {
        answer /= i;
    }
    printf("%.10lf\n", answer);
    return 0;
}