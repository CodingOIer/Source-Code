/**
 * @file AtCoder\ABC338\E.cpp
 * @author CodingOIer (redefinition0726@163.com)
 * @brief AtCoder
 * @version 1.0
 * @date 2024-01-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cstdio>
#include <stack>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN * 4];
std::stack<int> stack;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        p[a] = a;
        p[b] = a;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (p[i] == 0)
        {
            continue;
        }
        if (!stack.empty() && stack.top() == p[i])
        {
            stack.pop();
        }
        else
        {
            stack.push(p[i]);
        }
    }
    printf("%s\n", stack.empty() ? "No" : "Yes");
    return 0;
}