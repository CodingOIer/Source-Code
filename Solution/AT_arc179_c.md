## [ARC179C] Beware of Overflow 题解

### 思路分析

题目给出了我们 $2$ 种交互方式：

- `+ x y` 将 $a_z \gets a_x + a_y$，返回 $z$。
- `? x y` 返回 $a_x < a_y$。

对于第二种操作，可以视为给了我们一个比较函数，如下：

```cpp
bool cmp(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int r = 0;
    scanf("%d", &r);
    return r == 1;
}
```

接着，对于 $|a_i| \in [-R, R], |\sum_{i = 1}^{n}a_i| \in [-R, R]$，显然 $a_1 + a_n \in [-R, R]$​，证明如下：

---

$$
a_i \ge 0 \\
S = \sum_{i = 1}^{n}, T = \sum_{i = 2}^{n - 1} \\
\because 0 \le S \le R, a_i \ge 0 \\
\therefore T \le S \\
\because S \le R, T \le S \\
\therefore a_1 + a_n = S - T \le R \\
\because a_i \ge 0 \\
\therefore 0 \le a_1 + a_n \le R \Rightarrow a_1 + a_n \in [-R, R]
$$

---

$$
a_i \le 0 \\
S = \sum_{i = 1}^{n}, T = \sum_{i = 2}^{n - 1} \\
\because 0 \ge S \ge -R, a_i \le 0 \\
\therefore T \ge S \\
\because S \ge R, T \ge S \\
\therefore a_1 + a_n = T - S \ge R \\
\because a_i \le 0 \\
\therefore 0 \ge a_1 + a_n \ge R \Rightarrow a_1 + a_n \in [-R, R]
$$

---

$$
a_1 \le 0, a_n \ge 0 \\
\because a_1 \le 0, a_n \ge 0 \\
\therefore |a_1 + a_n| = ||a_1| - |a_n|| \\
\because |a_1| \in [0, R], |a_n| \in [0, R] \\
\therefore ||a_1| - |a_n|| \le R \Rightarrow a_1 + a_n \in [-R, R]
$$

---

所以，$|a_i| \in [-R, R], |\sum_{i = 1}^{n}a_i| \in [-R, R] \Rightarrow |a_1 + a_n| \in [-R, R]$。

我们每次选择最小的数字和最大的数字即可。

随便抓出一只数据结构维护即可。（比较次数不能大于 $\log_n$）

但是 $n \le 10^3$，所以我们使用二分后 $O(N)$ 插入即可。

但数据结构可以做到 $n \le 10^5$ 的。

### 代码实现

```cpp
#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e6 + 5;
int n;
int l, r;
int p[MaxN];
bool cmp(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int r = 0;
    scanf("%d", &r);
    return r == 1;
}
void insert(int x, int y)
{
    r++;
    for (int i = r; i > x; i--)
    {
        p[i] = p[i - 1];
    }
    p[x] = y;
}
int main()
{
    scanf("%d", &n);
    l = 1;
    r = n;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    std::sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        x = p[l];
        y = p[r];
        l++;
        r--;
        printf("+ %d %d\n", x, y);
        fflush(stdout);
        int k = 0;
        scanf("%d", &k);
        int a, b;
        a = l;
        b = r;
        int res = r + 1;
        for (; a <= b;)
        {
            int mid = (a + b) / 2;
            if (cmp(k, p[mid]))
            {
                res = mid;
                b = mid - 1;
            }
            else
            {
                a = mid + 1;
            }
        }
        insert(res, k);
    }
    printf("!\n");
    fflush(stdout);
    return 0;
}
```

