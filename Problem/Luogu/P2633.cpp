#include <algorithm>
#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
class node
{
  public:
    int value;
    node *left, *right;
    node()
    {
        value = 0;
        left = right = nullptr;
    }
    void update()
    {
        value = left->value + right->value;
    }
};
constexpr int MaxN = 1e5 + 5;
int n, m;
int p[MaxN];
int fa[MaxN];
int fid[MaxN];
int st[21][MaxN * 2];
node *ver[MaxN];
std::vector<int> r;
std::vector<int> v;
std::vector<int> g[MaxN];
int refto(int x)
{
    return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int explain(int x)
{
    return v[x - 1];
}
void build(node *c, int s, int t)
{
    if (s == t)
    {
        return;
    }
    int mid = (s + t) / 2;
    c->left = new node;
    c->right = new node;
    build(c->left, s, mid);
    build(c->right, mid + 1, t);
}
void change(node *pre, node *c, int s, int t, int w, int val)
{
    if (s == t)
    {
        c->value += val;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        c->right = pre->right;
        c->left = new node;
        change(pre->left, c->left, s, mid, w, val);
    }
    else
    {
        c->left = pre->left;
        c->right = new node;
        change(pre->right, c->right, mid + 1, t, w, val);
    }
    c->update();
}
int query(node *pre1, node *pre2, node *c1, node *c2, int s, int t, int rank)
{
    if (s == t)
    {
        return s;
    }
    int mid = (s + t) / 2;
    int leftSonSize = c1->left->value + c2->left->value - pre1->left->value - pre2->left->value;
    if (rank <= leftSonSize)
    {
        return query(pre1->left, pre2->left, c1->left, c2->left, s, mid, rank);
    }
    else
    {
        return query(pre1->right, pre2->right, c1->right, c2->right, mid + 1, t, rank - leftSonSize);
    }
}
void dfsInfo(int u, int f)
{
    fa[u] = f;
    r.push_back(u);
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfsInfo(v, u);
        r.push_back(u);
    }
}
void dfsMakeTree(int u, int f)
{
    change(ver[f], ver[u], 1, n, p[u], 1);
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfsMakeTree(v, u);
    }
}
int max(int x, int y)
{
    return fid[x] < fid[y] ? x : y;
}
int query(int l, int r)
{
    if (l > r)
    {
        std::swap(l, r);
    }
    int j = std::log2(r - l + 1);
    return max(st[j][l], st[j][r - (1 << j) + 1]);
}
int lca(int x, int y)
{
    return query(fid[x], fid[y]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        v.push_back(p[i]);
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++)
    {
        p[i] = refto(p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i <= n; i++)
    {
        ver[i] = new node;
    }
    build(ver[0], 1, n);
    r.push_back(0);
    dfsInfo(1, 0);
    dfsMakeTree(1, 0);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        fid[r[i]] = fid[r[i]] == 0 ? i : fid[r[i]];
        st[0][i] = r[i];
    }
    for (int j = 1; j <= 19; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= 2 * n - 1; i++)
        {
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    int lastAnswer = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, k;
        scanf("%d%d%d", &u, &v, &k);
        u ^= lastAnswer;
        int top = lca(u, v);
        int answer = query(ver[fa[top]], ver[top], ver[u], ver[v], 1, n, k);
        answer = explain(answer);
        printf("%d\n", answer);
        lastAnswer = answer;
    }
    return 0;
}
