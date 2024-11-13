/*
 * @Author: Redefinition
 * @Date: 2023-08-09 14:46:35
 * @LastEditors: Redefinition
 * @LastEditTime: 2023-08-09 18:07:34
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
const int MaxN = 1e5 + 5;
bool flag;
bool x[MaxN];
long long sum;
long long t, n;
long long p[MaxN];
void dfs(long long now, long long answer, long long cnt)
{
    if (cnt >= n)
    {
        return;
    }
    else if (answer % cnt == 0 && answer / cnt == sum / n)
    {
        flag = true;
    }
    else
    {
        for (long long i = 1; i <= n; i++)
        {
            if (flag)
            {
                return;
            }
            else if (!x[i])
            {
                if (flag)
                {
                    return;
                }
                x[i] = true;
                dfs(i, answer + p[i], cnt + 1);
                if (flag)
                {
                    return;
                }
                x[i] = false;
            }
        }
    }
    return;
}
void PlanA()
{
    for (long long i = 1; i <= n; i++)
    {
        if (!x[i])
        {
            flag = false;
            x[i] = true;
            dfs(i, p[i], 1);
            if (!flag)
            {
                x[i] = false;
            }
        }
    }
    flag = false;
    for (long long i = 1; i <= n; i++)
    {
        if (!x[i])
        {
            flag = true;
            printf("No\n");
            break;
        }
    }
    if (!flag)
    {
        printf("Yes\n");
    }
}
int main()
{
    scanf("%lld", &t);
    for (int u = 1; u <= t; u++)
    {
        memset(x, 0, sizeof(x));
        sum = 0;
        scanf("%lld", &n);
        for (long long i = 1; i <= n; i++)
        {
            scanf("%lld", &p[i]);
            sum += p[i];
        }
        sum += n * 1000;
        if (sum % n != 0 && n % sum != 0)
        {
            printf("No\n");
            continue;
        }
        sum -= n * 1000;
        flag = false;
        if (n <= 10)
        {
            PlanA();
        }
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}