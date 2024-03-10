## [ABC344E] Insert or Erase 题解

### 思路分析

感觉难度还不如 D 题。

由于这道题涉及到了大量的插入和删除操作，我们使用链表解决。

节点类的定义如下：

```cpp
class node
{
  public:
    int x;
    node *left;
    node *right;
    node()
    {
        x = 0;
        left = nullptr;
        right = nullptr;
    }
};
```

变量名为字面意思。

除此以外，我们用一个 `std::map<int, std::string>` 存储对应数值的节点的地址。每次插入和删除的代码如下：

```cpp
if (op == 1)
{
    int x, y;
    scanf("%d%d", &x, &y);
    auto b = map[x];
    auto k = new node;
    k->x = y;
    k->left = b;
    k->right = b->right;
    b->right->left = k;
    b->right = k;
    map[y] = k;
}
else if (op == 2)
{
    int x;
    scanf("%d", &x);
    auto k = map[x];
    node *l, *r;
    l = k->left;
    r = k->right;
    k->left->right = r;
    k->right->left = l;
    delete map[x];
    map[x] = nullptr;
}
```

### 代码实现

比较基础的链表题。

```cpp
#include <cstdio>
#include <unordered_map>
constexpr int MaxN = 2e5 + 5;
class node
{
  public:
    int x;
    node *left;
    node *right;
    node()
    {
        x = 0;
        left = nullptr;
        right = nullptr;
    }
};
int n, q;
node *head;
node *tail;
std::unordered_map<int, node *> map;
int main()
{
    scanf("%d", &n);
    head = new node;
    tail = new node;
    head->left = tail;
    head->right = tail;
    tail->left = head;
    tail->right = head;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        auto k = new node;
        k->x = x;
        k->left = tail->left;
        k->right = tail;
        tail->left->right = k;
        tail->left = k;
        map[x] = k;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            auto b = map[x];
            auto k = new node;
            k->x = y;
            k->left = b;
            k->right = b->right;
            b->right->left = k;
            b->right = k;
            map[y] = k;
        }
        else if (op == 2)
        {
            int x;
            scanf("%d", &x);
            auto k = map[x];
            node *l, *r;
            l = k->left;
            r = k->right;
            k->left->right = r;
            k->right->left = l;
            delete map[x];
            map[x] = nullptr;
        }
    }
    for (node *cur = head->right; cur != tail; cur = cur->right)
    {
        printf("%d ", cur->x);
    }
    printf("\n");
    return 0;
}
```