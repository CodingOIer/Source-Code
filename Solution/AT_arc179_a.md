## [ARC179A] Partition 题解

### 思路分析

贪心。

对于 $k \le 0$ 的情况，由于一开始我们就处于了 $Y_i \ge k$ 的部分，所以我们需要让 $Y_i$ 始终大于 $k$。

为了最大化成功的可能，我们先加上所以的正数，再减去所有的负数。

降序排序即可。

```cpp
std::sort(p + 1, p + 1 + n, [](int x, int y) { return x > y; });
long long s = 0;
for (int i = 1; i <= n; i++)
{
    s += p[i];
    if (s < k)
    {
        printf("No\n");
        return 0;
    }
}
printf("Yes\n");
for (int i = 1; i <= n; i++)
{
    printf("%d ", p[i]);
}
```

对于 $k \ge 0$ 的情况，我们在最初时处于 $Y_i \le 0$ 的部分，我们可以先让 $Y_i \ge k$，然后再 $\le k$。

升序排序即可，对于这种情况，没事失败的可能。

```cpp
std::sort(p + 1, p + 1 + n);
printf("Yes\n");
for (int i = 1; i <= n; i++)
{
    printf("%d ", p[i]);
}
```

### 代码实现

```cpp
#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, k;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    if (k <= 0)
    {
        std::sort(p + 1, p + 1 + n, [](int x, int y) { return x > y; });
        long long s = 0;
        for (int i = 1; i <= n; i++)
        {
            s += p[i];
            if (s < k)
            {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", p[i]);
        }
    }
    else
    {
        std::sort(p + 1, p + 1 + n);
        printf("Yes\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", p[i]);
        }
    }
    return 0;
}
```