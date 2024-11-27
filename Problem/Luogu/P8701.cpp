#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 1e5 + 5;
constexpr int MaxM = 1e2 + 5;
int n, m;
int value[MaxN];
char op[MaxM];
std::vector<int> tree[MaxN * 4];
void build(int c, int s, int t)
{
    tree[c] = {0, 0, 0, 0, 0, 0, 0, 0};
    if (s == t)
    {
        return;
    }
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
}
void upstream(int c, int s, int t)
{
    tree[c].clear();
    if (s == t)
    {
        tree[c].push_back(value[s]);
        for (; tree[c].size() < 8;)
        {
            tree[c].push_back(0);
        }
        return;
    }
    for (const auto &val : tree[c * 2])
    {
        tree[c].push_back(val);
    }
    for (const auto &val : tree[c * 2 + 1])
    {
        tree[c].push_back(val);
    }
    std::sort(tree[c].begin(), tree[c].end());
    std::reverse(tree[c].begin(), tree[c].end());
    for (; tree[c].size() > 8;)
    {
        tree[c].pop_back();
    }
    for (; tree[c].size() < 8;)
    {
        tree[c].push_back(0);
    }
}
void change(int c, int s, int t, int w, int val)
{
    if (s == t)
    {
        value[s] = val;
        upstream(c, s, t);
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change(c * 2, s, mid, w, val);
    }
    else
    {
        change(c * 2 + 1, mid + 1, t, w, val);
    }
    upstream(c, s, t);
}
std::vector<int> query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    std::vector<int> res;
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        const std::vector<int> &v = query(c * 2, s, mid, l, r);
        for (const auto &val : v)
        {
            res.push_back(val);
        }
    }
    if (r > mid)
    {
        const std::vector<int> &v = query(c * 2 + 1, mid + 1, t, l, r);
        for (const auto &val : v)
        {
            res.push_back(val);
        }
    }
    std::sort(res.begin(), res.end());
    std::reverse(res.begin(), res.end());
    for (; res.size() > 8;)
    {
        res.pop_back();
    }
    for (; res.size() < 8;)
    {
        res.push_back(0);
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        scanf(" ");
        scanf("%s", op);
        if (strcmp(op, "C") == 0)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            change(1, 1, n, x, y);
        }
        if (strcmp(op, "Q") == 0)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            const std::vector<int> &v = query(1, 1, n, l, r);
            printf("%d\n", v[7]);
        }
    }
    return 0;
}
