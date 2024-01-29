<!--
 * @Author: CodingOIer redefinition0726@163.com
 * @Date: 2024-01-29 16:01:38
 * @LastEditors: CodingOIer redefinition0726@163.com
 * @LastEditTime: 2024-01-29 16:07:07
 * @FilePath: \Source-Code\Solution\AT_abc338_e.md
 * 
 * Copyright (c) 2024 by CodingOIer, All Rights Reserved.
-->
## [ABC338E] Chords 题解

### 思路分析

在本题中，每一条线可以看为将圆切分成了两半，只要它不跨越了两个区域就没有交叉。

就是个括号序列嘛！

每次将对应的变放到数组中，然后就是括号序列，匹配完则为没有交叉，反之亦然。

### 代码实现

感觉本次的 E 题好简单~

```cpp
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
```