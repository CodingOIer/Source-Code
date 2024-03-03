#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
class node
{
  public:
    int size;
    int lc, rc;
    node()
    {
        lc = 0;
        rc = 0;
        size = 0;
    }
};
class island
{
  public:
    int h;
    int id;
    island()
    {
        h = 0;
        id = 0;
    }
};
class question
{
  public:
    int h;
    int id;
    int res;
    int l, r;
    question()
    {
        h = 0;
        l = 0;
        r = 0;
        id = 0;
        res = 0;
    }
};
int n, q;
island p[MaxN];
question answer[MaxN];
node tree[MaxN * 4];
node merge(node l, node r)
{
    node res;
    res.lc = l.lc;
    res.rc = r.rc;
    if (l.rc == 1 && r.lc == 1)
    {
        res.size = l.size + r.size - 1;
    }
    else
    {
        res.size = l.size + r.size;
    }
    return res;
}
node mergeResult(node l, node r)
{
    if (l.lc == -1)
    {
        return r;
    }
    return merge(l, r);
}
void change(int cur, int s, int t, int w)
{
    if (s == t)
    {
        tree[cur].lc = 1;
        tree[cur].rc = 1;
        tree[cur].size = 1;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change(cur * 2, s, mid, w);
    }
    else
    {
        change(cur * 2 + 1, mid + 1, t, w);
    }
    tree[cur] = merge(tree[cur * 2], tree[cur * 2 + 1]);
}
node query(int cur, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[cur];
    }
    int mid = (s + t) / 2;
    node res;
    res.lc = -1;
    if (l <= mid)
    {
        res = mergeResult(res, query(cur * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        res = mergeResult(res, query(cur * 2 + 1, mid + 1, t, l, r));
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i].h);
        p[i].id = i;
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d", &answer[i].l, &answer[i].r, &answer[i].h);
        answer[i].id = i;
    }
    std::sort(p + 1, p + 1 + n, [](const island &__x, const island &__y) { return __x.h > __y.h; });
    std::sort(answer + 1, answer + 1 + q, [](const question &__x, const question &__y) { return __x.h > __y.h; });
    int cnt = 1;
    for (int i = 1; i <= q; i++)
    {
        for (; cnt <= n && p[cnt].h > answer[i].h;)
        {
            change(1, 1, n, p[cnt].id);
            cnt++;
        }
        answer[i].res = query(1, 1, n, answer[i].l, answer[i].r).size;
    }
    std::sort(answer + 1, answer + 1 + q, [](const question &__x, const question &__y) { return __x.id < __y.id; });
    for (int i = 1; i <= q; i++)
    {
        printf("%d\n", answer[i].res);
    }
    return 0;
}