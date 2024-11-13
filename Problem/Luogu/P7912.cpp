#include <cstdio>
#include <queue>
#include <set>
constexpr int MaxN = 2e5 + 5;
class node
{
  public:
    int x;
    int id;
    node *left, *right;
    node(int a = 0, int b = 0)
    {
        x = a;
        id = b;
        left = right = nullptr;
    }
};
int n;
int p[MaxN];
node *head, *tail;
std::set<int> output;
std::set<node *> set;
std::set<node *> wait;
std::queue<node *> later;
inline void insert(node *ptr, node *l, node *r)
{
    if (l->x != ptr->x)
    {
        set.insert(ptr);
    }
    l->right = ptr;
    r->left = ptr;
    ptr->left = l;
    ptr->right = r;
}
inline void remove(node *ptr)
{
    node *l, *r;
    l = ptr->left;
    r = ptr->right;
    l->right = r;
    r->left = l;
    delete ptr;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    head = new node(-1);
    tail = new node(-1);
    head->right = tail;
    tail->left = head;
    for (int i = 1; i <= n; i++)
    {
        insert(new node(p[i], i), tail->left, tail);
    }
    for (; !set.empty();)
    {
        wait.clear();
        output.clear();
        for (auto x : set)
        {
            wait.insert(x);
            output.insert(x->id);
        }
        set.clear();
        for (auto x : output)
        {
            printf("%d%c", x, x == *output.rbegin() ? '\n' : ' ');
        }
        for (auto x : wait)
        {
            if (x->right != tail && x->x == x->right->x)
            {
                set.insert(x->right);
            }
            remove(x);
        }
        for (auto x : set)
        {
            if (x->x == x->left->x)
            {
                later.push(x);
            }
        }
        for (; !later.empty();)
        {
            set.erase(later.front());
            later.pop();
        }
    }
    return 0;
}