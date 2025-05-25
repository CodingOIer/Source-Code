#include <cstdio>
#include <cstring>
#include <queue>
class node
{
  public:
    int end;
    char by;
    node *fa;
    node *fail;
    node *to[26];
    node()
    {
        end = 0;
        by = '\0';
        fa = nullptr;
        fail = nullptr;
        for (int i = 0; i < 26; i++)
        {
            to[i] = nullptr;
        }
    }
};
constexpr int MaxL = 1e6 + 5;
constexpr int MaxN = 2e2 + 5;
constexpr int MaxM = 7e1 + 5;
int n, m;
int answer[MaxN];
char t[MaxL];
char s[MaxN][MaxM];
node *root;
int cc(char c)
{
    return c - 'a';
}
void addTrie(node *cur, char *s, int id)
{
    if (s[0] == '\0')
    {
        cur->end = id;
        return;
    }
    if (cur->to[cc(s[0])] == nullptr)
    {
        cur->to[cc(s[0])] = new node;
        cur->to[cc(s[0])]->by = s[0];
        cur->to[cc(s[0])]->fa = cur;
    }
    addTrie(cur->to[cc(s[0])], s + 1, id);
}
void build(node *root)
{
    std::queue<node *> queue;
    root->fail = root;
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
    if (cur->to[cc(c)] != nullptr)
    {
        return cur->to[cc(c)];
    }
    if (cur == root)
    {
        return root;
    }
    return forward(cur->fail, c);
}
void remove(node *cur)
{
    if (cur == nullptr)
    {
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        remove(cur->to[i]);
    }
    delete cur;
}
void solve()
{
    root = new node;
    for (int i = 1; i <= n; i++)
    {
        answer[i] = 0;
        scanf("%s", s[i] + 1);
        addTrie(root, s[i] + 1, i);
    }
    build(root);
    scanf("%s", t + 1);
    m = strlen(t + 1);
    auto cur = root;
    for (int i = 1; i <= m; i++)
    {
        cur = forward(cur, t[i]);
        auto cp = cur;
        for (; cp != root;)
        {
            answer[cp->end]++;
            cp = cp->fail;
        }
    }
    answer[0] = 0;
    int w = 0;
    for (int i = 1; i <= n; i++)
    {
        if (answer[i] > answer[w])
        {
            w = i;
        }
    }
    printf("%d\n", answer[w]);
    for (int i = 1; i <= n; i++)
    {
        if (answer[i] == answer[w])
        {
            printf("%s\n", s[i] + 1);
        }
    }
}
int main()
{
    for (;;)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        solve();
        remove(root);
    }
    return 0;
}