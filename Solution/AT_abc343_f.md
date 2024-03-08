## [ABC343F] Second Largest Query 题解

### 思路分析

考虑使用线段树。

对于线段树节点类的定义如下：

```cpp
class node
{
  public:
    int x;
    int max;
    int cnt_max;
    int second_max;
    int cnt_second_max;
    node()
    {
        x = 0;
        max = 0;
        cnt_max = 0;
        second_max = 0;
        cnt_second_max = 0;
    }
};
```

- $x$ 针对叶子节点，储存当前的数
- $max$ 为区间内最大值
- $cnt\_max$ 为区间最大值的个数
- $second\_max$ 为区间次大值
- $cnt\_second\_max$ 为区间次大值的个数

**因为在合并两个区间时，只有最大值和次大值可能有贡献。**

接着可以重载加法运算符：

```cpp
friend node operator+(const node &__x, const node &__y)
{
    node res;
    std::vector<std::pair<int, int>> temp;
    temp.push_back({__x.max, __x.cnt_max});
    temp.push_back({__x.second_max, __x.cnt_second_max});
    temp.push_back({__y.max, __y.cnt_max});
    temp.push_back({__y.second_max, __y.cnt_second_max});
    std::sort(temp.begin(), temp.end());
    res.max = temp[3].first;
    for (int i = 2; i >= 0; i--)
    {
        if (temp[i].first != temp[i + 1].first)
        {
            res.second_max = temp[i].first;
            break;
        }
    }
    for (auto x : temp)
    {
        if (x.first == res.max)
        {
            res.cnt_max += x.second;
        }
        if (x.first == res.second_max)
        {
            res.cnt_second_max += x.second;
        }
    }
    return res;
}
```

此处我们使用 `vector` 进行排序，然后取最大次，接着循环找出次大值（因为有可能最大次相同），最后循环累加出现次数。

接着正常的没有懒标记的单点修改线段树：

```cpp
node tree[MaxN * 4];
void build(int c, int s, int t)
{
    if (s == t)
    {
        tree[c].x = p[s];
        tree[c].update();
        return;
    }
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
    tree[c] = tree[c * 2] + tree[c * 2 + 1];
}
void change(int c, int s, int t, int w, int v)
{
    if (s == t)
    {
        tree[c].x = v;
        tree[c].update();
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change(c * 2, s, mid, w, v);
    }
    else
    {
        change(c * 2 + 1, mid + 1, t, w, v);
    }
    tree[c] = tree[c * 2] + tree[c * 2 + 1];
}
node query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    int mid = (s + t) / 2;
    node res;
    if (l <= mid)
    {
        res += query(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        res += query(c * 2 + 1, mid + 1, t, l, r);
    }
    return res;
}
```

### 代码实现

```cpp
#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
class node
{
  public:
    int x;
    int max;
    int cnt_max;
    int second_max;
    int cnt_second_max;
    node()
    {
        x = 0;
        max = 0;
        cnt_max = 0;
        second_max = 0;
        cnt_second_max = 0;
    }
    friend node operator+(const node &__x, const node &__y)
    {
        node res;
        std::vector<std::pair<int, int>> temp;
        temp.push_back({__x.max, __x.cnt_max});
        temp.push_back({__x.second_max, __x.cnt_second_max});
        temp.push_back({__y.max, __y.cnt_max});
        temp.push_back({__y.second_max, __y.cnt_second_max});
        std::sort(temp.begin(), temp.end());
        res.max = temp[3].first;
        for (int i = 2; i >= 0; i--)
        {
            if (temp[i].first != temp[i + 1].first)
            {
                res.second_max = temp[i].first;
                break;
            }
        }
        for (auto x : temp)
        {
            if (x.first == res.max)
            {
                res.cnt_max += x.second;
            }
            if (x.first == res.second_max)
            {
                res.cnt_second_max += x.second;
            }
        }
        return res;
    }
    friend void operator+=(node &__x, const node &__y)
    {
        __x = __x + __y;
    }
    void update()
    {
        max = x;
        cnt_max = 1;
        second_max = 0;
        cnt_second_max = 0;
    }
};
int n, q;
int p[MaxN];
node tree[MaxN * 4];
void build(int c, int s, int t)
{
    if (s == t)
    {
        tree[c].x = p[s];
        tree[c].update();
        return;
    }
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
    tree[c] = tree[c * 2] + tree[c * 2 + 1];
}
void change(int c, int s, int t, int w, int v)
{
    if (s == t)
    {
        tree[c].x = v;
        tree[c].update();
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change(c * 2, s, mid, w, v);
    }
    else
    {
        change(c * 2 + 1, mid + 1, t, w, v);
    }
    tree[c] = tree[c * 2] + tree[c * 2 + 1];
}
node query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    int mid = (s + t) / 2;
    node res;
    if (l <= mid)
    {
        res += query(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        res += query(c * 2 + 1, mid + 1, t, l, r);
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            change(1, 1, n, x, y);
        }
        else if (op == 2)
        {
            printf("%d\n", query(1, 1, n, x, y).cnt_second_max);
        }
    }
    return 0;
}
```