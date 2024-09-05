## [ARC138B] 01 Generation 题解

### 思路分析

正序构造很难，考虑逆序消除。

对于 B 操作，考虑记录一个 $=f$，表示这个序列是否被反转。

写出获取第 $w$ 位的数字和反转序列的代码。

```cpp
bool rf;
inline int get(int w)
{
    return p[w] ^ rf;
}
inline void rev()
{
    rf ^= true;
}
```

然后使用双指针，当末尾是 $0$ 的时候反复左移右指针。

末尾是 $1$ 的时候取反整个序列，在取反前先判断开头是不是 $0$，不是就不能构造，是就将左指针右移。

如果消完了，就是可以构造。

### 代码实现

```cpp
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
bool rf;
inline int get(int w)
{
    return p[w] ^ rf;
}
inline void rev()
{
    rf ^= true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int i, j;
    i = 1;
    j = n;
    for (; i <= j;)
    {
        for (; get(j) == 0;)
        {
            j--;
        }
        if (get(i) == 1)
        {
            printf("No\n");
            return 0;
        }
        i++;
        rev();
    }
    printf("Yes\n");
    return 0;
}
```

