#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 3e5 + 5;
class ques
{
  public:
    int id;
    int l, r, x;
    ques(int a, int b, int c, int i)
    {
        l = a;
        r = b;
        x = c;
        id = i;
    }
};
int n, m;
int answer[MaxN];
int tree[MaxN * 4];
std::pair<int, int> dog[MaxN];
void change(int c, int s, int t, int w, int v)
{
    if (s == t)
    {
        tree[c] += v;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change(c * 2, s, mid, w, v);
    }
    else
    {
        change(c * 2 + 1, mid + 1, t, w, v);
    }
    tree[c] = tree[c * 2] + tree[c * 2 + 1];
}
int query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    int mid = (s + t) / 2;
    int res = 0;
    if (l <= mid)
    {
        res += query(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        res += query(c * 2 + 1, mid + 1, t, l, r);
    }
    return res;
}
void calc(int l, int r, const std::vector<ques> &q)
{
    if (q.empty())
    {
        return;
    }
    if (l == r)
    {
        for (auto k : q)
        {
            answer[k.id] = dog[l].first;
        }
        return;
    }
    int mid = (l + r) / 2;
    for (int i = l; i <= mid; i++)
    {
        change(1, 1, n, dog[i].second, 1);
    }
    std::vector<ques> left;
    std::vector<ques> right;
    for (auto k : q)
    {
        int sum = query(1, 1, n, k.l, k.r);
        if (k.x <= sum)
        {
            left.push_back(k);
        }
        else
        {
            k.x -= sum;
            right.push_back(k);
        }
    }
    for (int i = l; i <= mid; i++)
    {
        change(1, 1, n, dog[i].second, -1);
    }
    calc(l, mid, left);
    calc(mid + 1, r, right);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        dog[i].first = x;
        dog[i].second = i;
    }
    std::sort(dog + 1, dog + 1 + n);
    std::vector<ques> q;
    for (int i = 1; i <= m; i++)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        q.push_back(ques(l, r, x, i));
    }
    calc(1, n, q);
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}