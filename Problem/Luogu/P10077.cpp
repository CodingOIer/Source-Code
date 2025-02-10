#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e5 + 5;
constexpr int Inf = 0x3f3f3f3f;
int n;
int read;
int p[MaxN];
int tree[MaxN * 4];
void build(int c, int s, int t)
{
    if (s == t)
    {
        tree[c] = p[s];
        return;
    }
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
    tree[c] = std::min(tree[c * 2], tree[c * 2 + 1]);
}
void update(int c, int s, int t, int val)
{
    if (s == t)
    {
        ++read;
        tree[c] = val;
        return;
    }
    int mid = (s + t) / 2;
    if (tree[c * 2] <= read)
    {
        update(c * 2, s, mid, val);
    }
    if (tree[c * 2 + 1] <= read)
    {
        update(c * 2 + 1, mid + 1, t, val);
    }
    tree[c] = std::min(tree[c * 2], tree[c * 2 + 1]);
}
int main()
{
    scanf("%*d%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &p[i]);
    }
    build(1, 1, n);
    for (int day = 1;; ++day)
    {
        int oldRead = read;
        update(1, 1, n, Inf);
        if (tree[1] == Inf)
        {
            printf("%d\n", day);
            break;
        }
        if (oldRead == read)
        {
            printf("-1\n");
            break;
        }
    }
    return 0;
}
