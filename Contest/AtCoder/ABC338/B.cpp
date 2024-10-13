/**
 * @file AtCoder\ABC338\B.cpp
 * @author CodingOIer (redefinition0726@163.com)
 * @brief AtCoder
 * @version 1.0
 * @date 2024-01-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e3 + 5;
int p[MaxN];
char s[MaxN];
int main()
{
    scanf("%s", s);
    int n = strlen(s);
    int max;
    for (int i = 0; i < n; i++)
    {
        p[s[i]]++;
        if (p[s[i]] > p[max] || (p[s[i]] == p[max] && s[i] < max))
        {
            max = s[i];
        }
    }
    printf("%c\n", max);
    return 0;
}