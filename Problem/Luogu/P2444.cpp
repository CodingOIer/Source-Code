#include <cstdio>
#include <queue>
constexpr int MaxN = 3e4 + 5;
constexpr int CharSet = 2;
class node
{
  public:
    char by;
    bool in;
    bool vis;
    bool bad;
    node *fa;
    node *fail;
    node *to[CharSet];
    node()
    {
        by = '\0';
        bad = false;
        fa = nullptr;
        fail = nullptr;
        for (int i = 0; i < CharSet; i++)
        {
            to[i] = nullptr;
        }
    }
    void updateBad()
    {
        auto cp = fail;
        for (; cp->fail != cp;)
        {
            bad |= cp->bad;
            cp = cp->fail;
        }
    }
};
int n;
char s[MaxN];
node *root;
int cc(char c)
{
    return c - '0';
}
void addTrie(node *cur, char *s)
{
    if (s[0] == '\0')
    {
        cur->bad = true;
        return;
    }
    if (cur->to[cc(s[0])] == nullptr)
    {
        cur->to[cc(s[0])] = new node;
        cur->to[cc(s[0])]->fa = cur;
        cur->to[cc(s[0])]->by = s[0];
    }
    addTrie(cur->to[cc(s[0])], s + 1);
}
void build(node *root)
{
    root->fail = root;
    root->updateBad();
    std::queue<node *> queue;
    for (int i = 0; i < CharSet; i++)
    {
        if (root->to[i] != nullptr)
        {
            root->to[i]->fail = root;
            queue.push(root->to[i]);
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
        cur->updateBad();
        for (int i = 0; i < CharSet; i++)
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
bool dfs(node *u)
{
    if (u->bad)
    {
        return false;
    }
    if (u->in)
    {
        return true;
    }
    if (u->vis)
    {
        return false;
    }
    u->in = true;
    u->vis = true;
    for (int i = 0; i < CharSet; i++)
    {
        if (dfs(forward(u, '0' + i)))
        {
            return true;
        }
    }
    u->in = false;
    return false;
}
int main()
{
    root = new node;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        addTrie(root, s + 1);
    }
    build(root);
    printf("%s\n", dfs(root) ? "TAK" : "NIE");
    return 0;
}