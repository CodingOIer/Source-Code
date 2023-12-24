#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
const int MaxN = 1e2 + 5;
int n, m;
int point[MaxN];
int kill[MaxN];
int solve[MaxN];
int need_solve[MaxN];
int not_solve[MaxN][MaxN * 2];
std::string oier[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &point[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> oier[i];
        for (int j = 0; j < oier[i].size(); j++)
        {
            if (oier[i][j] == 'o')
            {
                solve[i] += point[j + 1], need_solve[i] += point[j + 1];
            }
            else
            {
                kill[i]++;
                not_solve[i][kill[i]] = point[j + 1];
            }
        }
        solve[i] += i;
        need_solve[i] += i;
        std::sort(not_solve[i] + 1, not_solve[i] + 1 + kill[i]);
    }
    std::sort(need_solve + 1, need_solve + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        int less = solve[i];
        for (int j = kill[i]; j >= 1; j--)
        {
            if (less >= need_solve[n])
            {
                printf("%d\n", tmp);
                less = 0;
                break;
            }
            tmp++;
            less += not_solve[i][j];
        }
        if (less >= need_solve[n])
        {
            printf("%d\n", kill[i]);
        }
    }
    return 0;
}
