#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
class node
{
  public:
    int cx;
    char by;
    node *fa;
    node *fail;
    node *to[26];
    std::vector<int> end;
    node()
    {
        cx = 0;
        by = '\0';
        fa = nullptr;
        fail = nullptr;
        for (int i = 0; i < 26; i++)
        {
            to[i] = nullptr;
        }
    }
};
constexpr int MaxN = 2e5 + 5;
constexpr int MaxM = 2e6 + 5;
int n, m;
int answer[MaxN];
char s[MaxM];
node *root;
std::vector<node *> order;
int cc(char c)
{
    return c - 'a';
}
void addTrie(node *cur, char *s, int id)
{
    if (s[0] == '\0')
    {
        cur->end.push_back(id);
        return;
    }
    if (cur->to[cc(s[0])] == nullptr)
    {
        cur->to[cc(s[0])] = new node;
        cur->to[cc(s[0])]->fa = cur;
        cur->to[cc(s[0])]->by = s[0];
    }
    addTrie(cur->to[cc(s[0])], s + 1, id);
}
void build(node *root)
{
    std::queue<node *> queue;
    order.push_back(root);
    for (int i = 0; i < 26; i++)
    {
        if (root->to[i] != nullptr)
        {
            queue.push(root->to[i]);
            root->to[i]->fail = root;
        }
    }
    for (; !queue.empty();)
    {
        auto cur = queue.front();
        queue.pop();
        order.push_back(cur);
        if (cur->fail == nullptr)
        {
            auto cp = cur->fa->fail;
            for (;;)
            {
                if (cp->to[cc(cur->by)] != nullptr)
                {
                    cur->fail = cp->to[cc(cur->by)];
                    break;
                }
                if (cp == root)
                {
                    cur->fail = root;
                    break;
                }
                cp = cp->fail;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (cur->to[i] != nullptr)
            {
                queue.push(cur->to[i]);
            }
        }
    }
}
node *forward(node *cur, char c)
{
    return cur->to[cc(c)] != nullptr ? cur->to[cc(c)] : cur == root ? root : forward(cur->fail, c);
}
int main()
{
    root = new node;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        addTrie(root, s + 1, i);
    }
    build(root);
    scanf("%s", s + 1);
    m = strlen(s + 1);
    auto cur = root;
    for (int i = 1; i <= m; i++)
    {
        cur = forward(cur, s[i]);
        cur->cx++;
    }
    std::reverse(order.begin(), order.end());
    for (const auto &u : order)
    {
        for (const auto &val : u->end)
        {
            answer[val] += u->cx;
        }
        if (u->fail != nullptr)
        {
            u->fail->cx += u->cx;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}