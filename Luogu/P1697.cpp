/**
 * @Author: CodingOIer redefinition0726@163.com
 * @Date: 2024-02-01 17:24:17
 * @LastEditors: CodingOIer redefinition0726@163.com
 * @LastEditTime: 2024-02-01 17:32:48
 * @FilePath: \Source-Code\Luogu\P1697.cpp
 * @
 * @Copyright (c) 2024 by CodingOIer, All Rights Reserved.
 */
#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e2 + 5;
constexpr int MaxM = 1e3 + 5;
int n;
int l[MaxN];
int r[MaxN];
bool vis[MaxN];
int calc(int but)
{
    for (int i = 0; i <= 1000; i++)
    {
        vis[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == but)
        {
            continue;
        }
        for (int j = l[i]; j <= r[i]; j++)
        {
            vis[j] = true;
        }
    }
    int res = 0;
    for (int i = 0; i <= 1000; i++)
    {
        res += vis[i] ? 1 : 0;
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
    }
    int answer = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        answer = std::max(answer, calc(i));
    }
    printf("%d\n", answer);
    return 0;
}