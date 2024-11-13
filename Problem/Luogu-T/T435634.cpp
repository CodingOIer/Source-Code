/**
 * @Author: CodingOIer wanghongtiancodingoier@outlook.com
 * @Date: 2024-03-18 14:51:14
 * @LastEditors: CodingOIer wanghongtiancodingoier@outlook.com
 * @LastEditTime: 2024-03-18 15:01:57
 * @FilePath: \Source-Code\Luogu\T435634.cpp
 * @
 * @Copyright (c) 2024 by CodingOIer, All Rights Reserved.
 */
#include <cstdio>
int t;
int n, m;
void solve()
{
    scanf("%d%d", &n, &m);
    int res = -1;
    int bit = -1;
    for (int i = 1; i <= 9; i++)
    {
        long long temp = 0;
        int temp_bit = 0;
        for (int j = 1; j <= n; j++)
        {
            temp = temp * 10 + i;
            temp %= m;
            if (temp == 0)
            {
                temp_bit = j;
                break;
            }
        }
        if (temp == 0)
        {
            temp_bit = n / temp_bit * temp_bit;
            if (temp_bit > bit || (temp_bit == bit && i > res))
            {
                res = i;
                bit = temp_bit;
            }
        }
    }
    if (res == -1)
    {
        printf("-1\n");
        return;
    }
    for (int i = 1; i <= bit; i++)
    {
        printf("%d", res);
    }
    printf("\n");
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}