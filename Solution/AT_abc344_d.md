## [ABC344D] String Bags 题解

### 思路分析

显然是 dp 题。

我们设 $dp_{i, j}$ 的定义是：$i$ 为当前选择第 $i$ 组字符串，$j$ 表示当前总长度，储存最少的代价。

则可以写出 dp 代码：

```cpp
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= l; j++)
    {
        dp[i][j] = dp[i - 1][j];
        for (auto &k : p[i])
        {
            if (k.size() > j || !check(j, k))
            {
                continue;
            }
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j - k.size()] + 1);
        }
    }
}
```

其中 `bool check(int w, std::string k)` 返回 $s$ 的后 $w$ 位字符是否与 $k$ 相匹配。

### 代码实现

算比较基础的 dp 了。

```cpp
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int n, l;
int dp[MaxN][MaxN];
char s[MaxN];
char t[MaxN];
std::vector<std::string> p[MaxN];
bool check(int w, std::string k)
{
    for (int i = w; i >= w - k.size() + 1; i--)
    {
        if (s[i] != k[k.size() - (w - i + 1)])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%s", s + 1);
    scanf("%d", &n);
    l = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        int m;
        scanf("%d", &m);
        for (int j = 1; j <= m; j++)
        {
            scanf("%s", t);
            p[i].push_back(t);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            dp[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (auto &k : p[i])
            {
                if (k.size() > j || !check(j, k))
                {
                    continue;
                }
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - k.size()] + 1);
            }
        }
    }
    printf("%d\n", dp[n][l] == 0x3f3f3f3f ? -1 : dp[n][l]);
    return 0;
}
```