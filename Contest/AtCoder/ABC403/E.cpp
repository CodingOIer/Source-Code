#include <cstdio>
#include <cstring>
constexpr int MaxN = 5e5 + 5;
class node
{
  public:
    int here;
    int after;
    int stop;
    node *next[26];
    node()
    {
        here = 0;
        after = 0;
        stop = 0;
        for (int i = 0; i < 26; i++)
        {
            next[i] = nullptr;
        }
    }
    void update()
    {
        if (stop != 0)
        {
            after = 0;
            return;
        }
        after = here;
        for (int i = 0; i < 26; i++)
        {
            after += next[i] == nullptr ? 0 : next[i]->after;
        }
    }
};
int n, m;
node *root;
char s[MaxN];
void makeSure(node *cur, int w)
{
    if (w == m)
    {
        return;
    }
    if (cur->next[s[w + 1] - 'a'] == nullptr)
    {
        cur->next[s[w + 1] - 'a'] = new node;
    }
    makeSure(cur->next[s[w + 1] - 'a'], w + 1);
}
void addPrefix(node *cur, int w)
{
    if (w == m)
    {
        return;
    }
    if (w == m - 1)
    {
        cur->stop++;
    }
    addPrefix(cur->next[s[w + 1] - 'a'], w + 1);
    cur->update();
}
void addString(node *cur, int w)
{
    if (w == m)
    {
        return;
    }
    if (w == m - 1)
    {
        cur->here++;
    }
    addString(cur->next[s[w + 1] - 'a'], w + 1);
    cur->update();
}
int main()
{
    scanf("%d", &n);
    root = new node;
    for (int i = 1; i <= n; i++)
    {
        int op;
        scanf("%d", &op);
        scanf(" ");
        scanf("%s", s);
        m = strlen(s);
        makeSure(root, -1);
        if (op == 1)
        {
            addPrefix(root, -1);
        }
        else if (op == 2)
        {
            addString(root, -1);
        }
        printf("%d\n", root->after);
    }
    return 0;
}