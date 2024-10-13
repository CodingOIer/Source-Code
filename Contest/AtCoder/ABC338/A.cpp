/**
 * @file AtCoder\ABC338\A.cpp
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
constexpr int MaxN = 1e2 + 5;
char s[MaxN];
int main()
{
    scanf("%s", s);
    if ('a' <= s[0] && s[0] <= 'z')
    {
        printf("No\n");
        return 0;
    }
    for (int i = 1; i < strlen(s); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}