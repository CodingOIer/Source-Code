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
constexpr int MaxN = 1e6 + 5;
int n, m;
char s[MaxN];
bool vis[MaxN];
node *root;
int cc(char c)
{
    return c - 'a';
}
void addTrie(node *cur, char *s, int id)
{
    if (s[0] == '\0')
    {
        cur->end++;
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
    root->fail = root;
    for (int i = 0; i < 26; i++)
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
    node *cur = root;
    scanf("%s", s + 1);
    m = strlen(s + 1);
    int answer = 0;
    for (int i = 1; i <= m; i++)
    {
        cur = forward(cur, s[i]);
        answer += cur->end;
        cur->end = 0;
    }
    printf("%d\n", answer);
    return 0;
}