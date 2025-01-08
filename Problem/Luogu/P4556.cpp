#include <algorithm>
#include <cassert>
#include <cstdio>
#include <tuple>
#include <vector>
class node
{
  public:
    int x;
    int id;
    bool end;
    node *left, *right;
    std::tuple<int, int> most;
    node()
    {
        x = 0;
        id = 0;
        end = false;
        most = {0, 0};
        left = right = nullptr;
    }
    void upstream()
    {
        if (end)
        {
            most = {x, x == 0 ? 0 : id};
        }
        else
        {
            if (left == nullptr && right == nullptr)
            {
                most = {0, 0};
            }
            else if (left == nullptr)
            {
                most = right->most;
            }
            else if (right == nullptr)
            {
                most = left->most;
            }
            else
            {
                if (std::get<0>(left->most) > std::get<0>(right->most) ||
                    (std::get<0>(left->most) == std::get<0>(right->most) &&
                     std::get<1>(left->most) < std::get<1>(right->most)))
                {
                    most = left->most;
                }
                else
                {
                    most = right->most;
                }
            }
        }
    }
};
constexpr int MaxN = 1e5 + 5;
constexpr int MaxValue = 1e5;
int n, m;
int fa[MaxN];
int fi[MaxN];
int answer[MaxN];
int lg2[MaxN * 2];
int st[21][MaxN * 2];
node *root[MaxN];
std::vector<int> r;
std::vector<int> g[MaxN];
void dfs(int u, int f)
{
    fa[u] = f;
    r.push_back(u);
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
        r.push_back(u);
    }
}
int topSt(int u, int v)
{
    return fi[u] < fi[v] ? u : v;
}
int LCA(int u, int v)
{
    int l = std::min(fi[u], fi[v]);
    int r = std::max(fi[u], fi[v]);
    int j = lg2[r - l + 1];
    return topSt(st[j][l], st[j][r - (1 << j) + 1]);
}
node *merge(node *a, node *b)
{
    if (a == nullptr && b == nullptr)
    {
        return nullptr;
    }
    if (a == nullptr)
    {
        return b;
    }
    if (b == nullptr)
    {
        return a;
    }
    if (a->end && b->end)
    {
        node *c = new node;
        c->end = true;
        c->id = a->id;
        c->x = a->x + b->x;
        c->upstream();
        return c;
    }
    else
    {
        node *c = new node;
        node *r = merge(a->left, b->left);
        if (r != nullptr)
        {
            c->left = r;
        }
        r = merge(a->right, b->right);
        if (r != nullptr)
        {
            c->right = r;
        }
        c->upstream();
        return c;
    }
}
void change(node *cur, int s, int t, int w, int val)
{
    if (s == t)
    {
        cur->x += val;
        cur->id = w;
        cur->end = true;
        cur->upstream();
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        if (cur->left == nullptr)
        {
            cur->left = new node;
        }
        change(cur->left, s, mid, w, val);
    }
    else
    {
        if (cur->right == nullptr)
        {
            cur->right = new node;
        }
        change(cur->right, mid + 1, t, w, val);
    }
    cur->upstream();
}
void dfsCalc(int u, int f)
{
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfsCalc(v, u);
        root[u] = merge(root[u], root[v]);
    }
    answer[u] = std::get<1>(root[u]->most);
}
int main()
{
    scanf("%d%d", &n, &m);
    lg2[1] = 0;
    for (int i = 2; i <= 2 * n - 1; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    r.push_back(0);
    dfs(1, 0);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        st[0][i] = r[i];
        fi[r[i]] = fi[r[i]] == 0 ? i : fi[r[i]];
    }
    for (int j = 1; j < 19; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= 2 * n - 1; i++)
        {
            st[j][i] = topSt(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        root[i] = new node;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        int top = LCA(u, v);
        change(root[u], 1, MaxValue, w, 1);
        change(root[v], 1, MaxValue, w, 1);
        change(root[top], 1, MaxValue, w, -1);
        if (fa[top] != 0)
        {
            change(root[fa[top]], 1, MaxValue, w, -1);
        }
    }
    dfsCalc(1, 0);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}
