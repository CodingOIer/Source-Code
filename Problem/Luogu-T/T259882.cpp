/**
 * @file Luogu\T259882.cpp
 * @author CodingOIer (redefinition0726@163.com)
 * @brief Luogu
 * @version 1.0
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cstdio>
#include <map>
constexpr int MaxN = 25;
int n;
int answer;
int main()
{
    scanf("%d", &n);
    answer = 1;
    char last = '\0';
    for (int i = 1; i <= n; i++)
    {
        char s[5];
        scanf("%s", s);
        if (s[0] != last)
        {
            answer++;
            last = s[0];
        }
    }
    printf("%d\n", answer);
    return 0;
}