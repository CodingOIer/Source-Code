## [ABC344C] A+B+C 题解

### 思路分析

我们注意到 $O(N^3)$ 的时间复杂度可以通过，但如果我们每次询问的时候都扫一遍则会超时。

我们可以预处理所有的和，将其保存在一颗红黑树中，即可 $O(N^3 + Q)$ 通过此题。

### 代码实现

```cpp
#include <cstdio>
#include <unordered_map>
constexpr int MaxN = 1e2 + 5;
constexpr int MaxQ = 2e5 + 5;
int n, m, l, q;
int a[MaxN];
int b[MaxN];
int c[MaxN];
std::unordered_map<int, bool> map;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    scanf("%d", &l);
    for (int i = 1; i <= l; i++)
    {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= l; k++)
            {
                map[a[i] + b[j] + c[k]] = true;
            }
        }
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%s\n", map[x] ? "Yes" : "No");
    }
    return 0;
}
```