## Polyomino

### 思路分析

分为以下几个步骤：

1. 输入。
2. 对其进行分割。
3. 暴力进行旋转、平移。

得到的代码结构为：

```cpp
bool check();
void dfs(int x);
void rotate(int id);
int main();
```

对于输入，使用 `char` 的三维数组进行存储：

```cpp
for (int i = 1; i <= 3; i++)
{
    for (int j = 1; j <= n; j++)
    {
        scanf("%s", s[i][j] + 1);
    }
}
```

为了增加代码可读性，使用 `class` 进行存储，结构如下：

```cpp
class block
{
  public:
    int h, w;
    int block[MaxN][MaxN];
};
```

对于分割，我们找到高度、宽度，并将其存入 `block` 中：

```cpp
for (int id = 1; id <= 3; id++)
{
    int start_h;
    start_h = 1;
    for (; !haveH(id, start_h);)
    {
        start_h++;
    }
    int end_h;
    end_h = n;
    for (; !haveH(id, end_h);)
    {
        end_h--;
    }
    int start_w;
    start_w = 1;
    for (; !haveW(id, start_w);)
    {
        start_w++;
    }
    int end_w;
    end_w = n;
    for (; !haveW(id, end_w);)
    {
        end_w--;
    }
    p[id].h = end_h - start_h + 1;
    p[id].w = end_w - start_w + 1;
    for (int i = start_h; i <= end_h; i++)
    {
        for (int j = start_w; j <= end_w; j++)
        {
            p[id].block[i - start_h + 1][j - start_w + 1] = (s[id][i][j] == '#') ? 1 : 0;
        }
    }
}
```

这里需要 $2$ 个辅助函数：

```cpp
bool haveH(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (s[x][y][i] == '#')
        {
            return true;
        }
    }
    return false;
}
bool haveW(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (s[x][i][y] == '#')
        {
            return true;
        }
    }
    return false;
}
```

接着，就是令人头大的旋转操作了，大家可以在纸上模拟，可以证明 $s_{i,j}$ 将会旋转到 $s_{j,H-i+1}$ 的位置上（这个函数改了我半个小时）：

```cpp
void rotate(int id)
{
    block t;
    t.h = p[id].w;
    t.w = p[id].h;
    for (int i = 1; i <= p[id].h; i++)
    {
        for (int j = 1; j <= p[id].w; j++)
        {
            t.block[j][p[id].h - i + 1] = p[id].block[i][j];
        }
    }
    p[id] = t;
}
```

最后就是无脑深搜了：

```cpp
void dfs(int id)
{
    if (id == 4)
    {
        check();
    }
    else
    {
        for (int r = 1; r <= 4; r++)
        {
            for (int x = 0; x <= n - p[id].h; x++)
            {
                for (int y = 0; y <= n - p[id].w; y++)
                {
                    for (int i = 1; i <= p[id].h; i++)
                    {
                        for (int j = 1; j <= p[id].w; j++)
                        {
                            sum[i + x][j + y] += p[id].block[i][j];
                        }
                    }
                    dfs(id + 1);
                    for (int i = 1; i <= p[id].h; i++)
                    {
                        for (int j = 1; j <= p[id].w; j++)
                        {
                            sum[i + x][j + y] -= p[id].block[i][j];
                        }
                    }
                }
            }
            rotate(id);
        }
    }
}
```

对于答案的验证问题，我们只需要对每一个有格子的位置加上 $1$，如果有地方为 $0$，则表示没有覆盖，若超过 $1$ 则表示被重复覆盖，均不能作为答案。

下面是 `check` 函数：

```cpp
void check()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (sum[i][j] != 1)
            {
                return;
            }
        }
    }
    printf("Yes\n");
    exit(0);
}
```

注：`exit(0)` 表示结束程序并返回 `0`。

将代码组合就是如下的代码：

```cpp
#include <cstdio>
#include <cstdlib>
const int MaxN = 7;
class block
{
  public:
    int h, w;
    int block[MaxN][MaxN];
};
int n;
int sum[MaxN][MaxN];
char s[MaxN][MaxN][MaxN];
block p[5];
bool haveH(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (s[x][y][i] == '#')
        {
            return true;
        }
    }
    return false;
}
bool haveW(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (s[x][i][y] == '#')
        {
            return true;
        }
    }
    return false;
}
void rotate(int id)
{
    block t;
    t.h = p[id].w;
    t.w = p[id].h;
    for (int i = 1; i <= p[id].h; i++)
    {
        for (int j = 1; j <= p[id].w; j++)
        {
            t.block[j][p[id].h - i + 1] = p[id].block[i][j];
        }
    }
    p[id] = t;
}
void check()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (sum[i][j] != 1)
            {
                return;
            }
        }
    }
    printf("Yes\n");
    exit(0);
}
void dfs(int id)
{
    if (id == 4)
    {
        check();
    }
    else
    {
        for (int r = 1; r <= 4; r++)
        {
            for (int x = 0; x <= n - p[id].h; x++)
            {
                for (int y = 0; y <= n - p[id].w; y++)
                {
                    for (int i = 1; i <= p[id].h; i++)
                    {
                        for (int j = 1; j <= p[id].w; j++)
                        {
                            sum[i + x][j + y] += p[id].block[i][j];
                        }
                    }
                    dfs(id + 1);
                    for (int i = 1; i <= p[id].h; i++)
                    {
                        for (int j = 1; j <= p[id].w; j++)
                        {
                            sum[i + x][j + y] -= p[id].block[i][j];
                        }
                    }
                }
            }
            rotate(id);
        }
    }
}
int main()
{
    n = 4;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%s", s[i][j] + 1);
        }
    }
    for (int id = 1; id <= 3; id++)
    {
        int start_h;
        start_h = 1;
        for (; !haveH(id, start_h);)
        {
            start_h++;
        }
        int end_h;
        end_h = n;
        for (; !haveH(id, end_h);)
        {
            end_h--;
        }
        int start_w;
        start_w = 1;
        for (; !haveW(id, start_w);)
        {
            start_w++;
        }
        int end_w;
        end_w = n;
        for (; !haveW(id, end_w);)
        {
            end_w--;
        }
        p[id].h = end_h - start_h + 1;
        p[id].w = end_w - start_w + 1;
        for (int i = start_h; i <= end_h; i++)
        {
            for (int j = start_w; j <= end_w; j++)
            {
                p[id].block[i - start_h + 1][j - start_w + 1] = (s[id][i][j] == '#') ? 1 : 0;
            }
        }
    }
    dfs(1);
    printf("No\n");
    return 0;
}
```