/**
 * @file AtCoder\ABC338\F.cpp
 * @author CodingOIer (redefinition0726@163.com)
 * @brief AtCoder
 * @version 1.0
 * @date 2024-01-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <cstdio>
constexpr int MaxN = 25;
int n, m;
int answer;
int p[MaxN][MaxN];
bool vis[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = 0x3f3f3f3f;
            if (i == j)
            {
                p[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        p[u][v] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[i][k] + p[k][j] < p[i][j])
                {
                    p[i][j] = p[i][k] + p[k][j];
                }
            }
        }
    }
    int answer = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= n; j++)
        {
            vis[j] = false;
        }
        int now = i;
        for (int j = 1; j <= n; j++)
        {
            vis[now] = true;
            if (j == n)
            {
                break;
            }
            int res = 0;
            for (int k = 1; k <= n; k++)
            {
                if (!vis[k] && (res == 0 || p[now][k] < p[now][res]))
                {
                    res = k;
                }
            }
            temp += p[now][res];
            now = res;
        }
        answer = std::min(answer, temp);
    }
    printf("%d\n", answer);
    return 0;
}