#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
class node
{
  public:
    int len;
    node *link;
    node *ref[26];
    node()
    {
        len = 0;
        link = nullptr;
    }
};
constexpr int MaxN = 1e2 + 5;
int n;
int size[MaxN];
char s[MaxN];
long long answer;
node *root;
node *last;
node *dirRef[MaxN];
std::vector<int> g[MaxN];
std::map<node *, int> map;
std::map<node *, bool> vis;
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
int getId(node *cur)
{
    if (map.count(cur))
    {
        return map[cur];
    }
    map[cur] = map.size() + 1;
    dirRef[map[cur]] = cur;
    return map[cur];
}
void dfs(node *cur)
{
    if (vis[cur])
    {
        return;
    }
    vis[cur] = true;
    if (cur->link != nullptr)
    {
        int u, v;
        u = getId(cur);
        v = getId(cur->link);
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
    answer = std::max(answer, 1ll * size[u] * dirRef[u]->len);
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
    calc(getId(root), -1);
    printf("%lld\n", answer);
    return 0;
}
