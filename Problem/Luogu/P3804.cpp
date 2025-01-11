#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 2e6 + 5;
class node;
node *dirRef[MaxN];
int globalNodeId;
class node
{
  public:
    int id;
    int len;
    node *link;
    node *ref[26];
    node()
    {
        id = ++globalNodeId;
        dirRef[id] = this;
        len = 0;
        link = nullptr;
    }
};
int n;
int size[MaxN];
char s[MaxN];
bool vis[MaxN];
long long answer;
node *root;
node *last;
std::vector<int> g[MaxN];
void expand(char ch)
{
    int id = ch - 'a';
    node *cur = new node;
    cur->len = last->len + 1;
    node *ptr = last;
    for (;;)
    {
        if (ptr->ref[id] == nullptr)
        {
            ptr->ref[id] = cur;
            if (ptr == root)
            {
                cur->link = root;
                break;
            }
            ptr = ptr->link;
            continue;
        }
        if (ptr->ref[id]->len == ptr->len + 1)
        {
            cur->link = ptr->ref[id];
            break;
        }
        node *next = ptr->ref[id];
        node *cp = new node;
        cp->len = ptr->len + 1;
        cp->link = next->link;
        cur->link = cp;
        memcpy(cp->ref, next->ref, sizeof(cp->ref));
        for (;;)
        {
            if (ptr->ref[id] != next)
            {
                break;
            }
            ptr->ref[id] = cp;
            if (ptr->link == nullptr)
            {
                break;
            }
            ptr = ptr->link;
        }
        break;
    }
    last = cur;
}
void dfs(node *cur)
{
    if (vis[cur->id])
    {
        return;
    }
    vis[cur->id] = true;
    if (cur->link != nullptr)
    {
        int u, v;
        u = cur->id;
        v = cur->link->id;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < 26; i++)
    {
        if (cur->ref[i] != nullptr)
        {
            dfs(cur->ref[i]);
        }
    }
}
void calc(int u, int f)
{
    size[u] = 1;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        calc(v, u);
        size[u] += size[v];
    }
    if (size[u] >= 2)
    {
        answer = std::max(answer, 1ll * dirRef[u]->len * size[u]);
    }
}
int main()
{
    root = last = new node;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        expand(s[i]);
    }
    dfs(root);
    calc(root->id, 0);
    printf("%lld\n", answer);
    return 0;
}
