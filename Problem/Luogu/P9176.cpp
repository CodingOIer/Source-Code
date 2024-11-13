#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
class student
{
  public:
    int h;
    long long cnt;
    student()
    {
        h = 0;
        cnt = 0;
    }
};
int n;
int sl;
int s[MaxN];
student ask[MaxN];
long long tree[MaxN * 4];
inline int link(int x)
{
    return std::lower_bound(s + 1, s + 1 + sl, x) - s;
}
void change(int c, int s, int t, int w, long long v)
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
int query(int c, int s, int t, long long v)
{
    if (s == t)
    {
        return s;
    }
    int mid = (s + t) / 2;
    if (v <= tree[c * 2])
    {
        return query(c * 2, s, mid, v);
    }
    else
    {
        return query(c * 2 + 1, mid + 1, t, v - tree[c * 2]);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%lld", &ask[i].h, &ask[i].cnt);
        s[i] = ask[i].h;
    }
    std::sort(s + 1, s + 1 + n);
    sl = std::unique(s + 1, s + 1 + n) - s - 1;
    for (int i = 1; i <= n; i++)
    {
        ask[i].h = link(ask[i].h);
    }
    for (int i = 1; i <= n; i++)
    {
        change(1, 1, n, ask[i].h, ask[i].cnt);
        long long sum = tree[1];
        if (sum % 2 == 1)
        {
            sum = sum / 2 + 1;
        }
        else
        {
            sum = sum / 2;
        }
        printf("%d\n", s[query(1, 1, n, sum)]);
    }
    return 0;
}