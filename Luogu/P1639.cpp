/**
 * @file Luogu\P1639.cpp
 * @author CodingOIer (redefinition0726@163.com)
 * @brief Luogu
 * @version 1.0
 * @date 2024-01-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
int a, b, x, y;
int main()
{
    scanf("%d%d%d%d", &a, &b, &x, &y);
    printf("%d\n", std::min({abs(a - b), abs(a - x) + abs(b - y), abs(a - y) + abs(b - x)}));
    return 0;
}