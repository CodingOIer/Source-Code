## [ARC111B] Reversible Cards 题解

### 思路分析

看着这个题的输入就很像一个图，所以我们先把图建出来试一试……

发现对于每一条边，其可以分配到其端点之一上。

扩展到树，假设其有 $n$ 个点，则它对答案的贡献为 $n - 1$，因为它只有 $n - 1$ 条边。

但对于一个简单环，假设其有 $n$ 个点，那么它绝对有 $n$ 条边。而且如果想在其上面增加点，则必须对应地增加边。

所以答案统计如下：

对于每一个大小为 $n$ 的联通块：

- 如果它包含一个环，则 $answer \gets answer + n$。
- 否则，$answer \gets answer + (n - 1)$。

注意，由于本题可能会有重边，所以请在第一次遍历到父亲边是将父亲设置为一个特殊的值来支持重边。（自环同理）

### 代码实现

```cpp
#include <cstdio>
#include <vector>
constexpr int MaxN = 4e5 + 5;
int n;
int answer;
bool back;
bool vis[MaxN];
std::vector<int> link[MaxN];
int dfs(int u, int f)
{
    if (vis[u])
    {
        back = true;
        return 0;
    }
    vis[u] = true;
    int size = 1;
    for (auto v : link[u])
    {
        if (v == f)
        {
            f = 0;
            continue;
        }
        size += dfs(v, u);
    }
    return size;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    for (int i = 1; i <= 400000; i++)
    {
        if (link[i].size() == 0)
        {
            continue;
        }
        back = false;
        int size = dfs(i, 0);
        if (back)
        {
            answer += size;
        }
        else
        {
            answer += size - 1;
        }
    }
    printf("%d\n", answer);
    return 0;
}
```