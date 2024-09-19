#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
class node;
node *find(node *);
std::vector<node *> rubbish;
class node
{
  public:
    bool rm;
    long long value;
    node *ref;
    node *le, *ri;
    inline node()
    {
        rubbish.push_back(this);
        rm = false;
        value = 0x7f7f7f7f7f7f7f;
        ref = nullptr;
        le = ri = nullptr;
    }
    inline node *left()
    {
        if (le->rm)
        {
            le = find(le);
        }
        return le;
    }
    inline node *right()
    {
        if (ri->rm)
        {
            ri = find(ri);
        }
        return ri;
    }
};
int n;
node *head, *tail;
std::priority_queue<std::tuple<int, node *>, std::vector<std::tuple<int, node *>>,
                    std::greater<std::tuple<int, node *>>>
    queue;
inline node *find(node *ptr)
{
    for (; ptr->rm;)
    {
        if (ptr != nullptr)
        {
            ptr = ptr->ref;
        }
    }
    return ptr;
}
inline node *merge(node *a, node *b)
{
    node *ptr = new node;
    a->rm = true;
    b->rm = true;
    a->ref = ptr;
    b->ref = ptr;
    ptr->le = a->left();
    ptr->ri = b->right();
    ptr->value = std::max(a->value, b->value);
    return ptr;
}
inline void insert(node *pre, node *ptr)
{
    pre->right()->le = ptr;
    ptr->ri = pre->right();
    pre->ri = ptr;
    ptr->le = pre;
}
inline void clear()
{
    for (auto k : rubbish)
    {
        delete k;
    }
    rubbish.clear();
}
void solve()
{
    scanf("%d", &n);
    head = new node;
    tail = new node;
    head->le = head->ri = tail;
    tail->le = tail->ri = head;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        node *ptr = new node;
        ptr->value = x;
        insert(tail->left(), ptr);
        queue.push({x, ptr});
    }
    long long answer = 0;
    for (int _ = 1; _ <= n - 1; _++)
    {
        node *ptr;
        std::tie(std::ignore, ptr) = queue.top();
        queue.pop();
        if (ptr->rm)
        {
            _--;
            continue;
        }
        if (ptr->left()->value - ptr->value < ptr->right()->value - ptr->value)
        {
            answer += ptr->left()->value - ptr->value;
            ptr = merge(ptr->left(), ptr);
        }
        else
        {
            answer += ptr->right()->value - ptr->value;
            ptr = merge(ptr, ptr->right());
        }
        queue.push({ptr->value, ptr});
    }
    for (; !queue.empty();)
    {
        queue.pop();
    }
    printf("%lld\n", answer);
    clear();
}
int main()
{
    int c, t;
    scanf("%d%d", &c, &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}