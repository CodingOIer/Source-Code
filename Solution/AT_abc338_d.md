<!--
 * @Author: CodingOIer redefinition0726@163.com
 * @Date: 2024-01-29 15:48:20
 * @LastEditors: CodingOIer redefinition0726@163.com
 * @LastEditTime: 2024-01-29 16:01:04
 * @FilePath: \Source-Code\Solution\AT_abc338_d.md
 * 
 * Copyright (c) 2024 by CodingOIer, All Rights Reserved.
-->
## [ABC338D] Island Tour

### 思路分析

考虑枚举每一对相邻的路径中的点，计算对答案的贡献。

考虑下面这张图。

![](https://cdn.luogu.com.cn/upload/image_hosting/3bfrvb1o.png)

显而易见，断开 $a$ 中的任意点的贡献为 $b$ 的长度，$b$ 亦然。

考虑使用线段树维护区间最小值，需要用到边权转点权，本文使边 $x$ 到 $x + 1$ 边的权值放在 $x$ 上。

写出修改代码。

```cpp
void change(int l, int r, long long val)
{
    if (l <= r)
    {
        tree_change(1, 1, n, l, r - 1, val);
    }
    else
    {
        tree_change(1, 1, n, l, n, val);
        tree_change(1, 1, n, 1, r - 1, val);
    }
}
```

请读者自行思考 `if` 语句的含义。

### 代码实现

Tips: 本题的答案可能不适用于 $32$ 位有符号整数。

```cpp
/**
 * @file AtCoder\ABC338\D.cpp
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
constexpr int MaxN = 2e5 + 5;
int n, m;
int p[MaxN];
long long tree[MaxN * 4];
long long lazy[MaxN * 4];
void downstream(int cur, int s, int t)
{
    if (lazy[cur] != 0)
    {
        tree[cur * 2] += lazy[cur];
        tree[cur * 2 + 1] += lazy[cur];
        lazy[cur * 2] += lazy[cur];
        lazy[cur * 2 + 1] += lazy[cur];
        lazy[cur] = 0;
    }
}
void tree_change(int cur, int s, int t, int l, int r, long long val)
{
    if (l > r)
    {
        return;
    }
    if (l <= s && t <= r)
    {
        tree[cur] += val;
        lazy[cur] += val;
        return;
    }
    downstream(cur, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        tree_change(cur * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        tree_change(cur * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[cur] = std::min(tree[cur * 2], tree[cur * 2 + 1]);
}
long long query(int cur, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[cur];
    }
    downstream(cur, s, t);
    int mid = (s + t) / 2;
    long long res = 0x3f3f3f3f3f3f3f3f;
    if (l <= mid)
    {
        res = std::min(res, query(cur * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        res = std::min(res, query(cur * 2 + 1, mid + 1, t, l, r));
    }
    return res;
}
void change(int l, int r, long long val)
{
    if (l <= r)
    {
        tree_change(1, 1, n, l, r - 1, val);
    }
    else
    {
        tree_change(1, 1, n, l, n, val);
        tree_change(1, 1, n, 1, r - 1, val);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 2; i <= m; i++)
    {
        int x, y;
        x = p[i - 1];
        y = p[i];
        if (x > y)
        {
            std::swap(x, y);
        }
        change(y, x, y - x);
        change(x, y, n - (y - x));
    }
    printf("%lld\n", query(1, 1, n, 1, n));
    return 0;
}
```