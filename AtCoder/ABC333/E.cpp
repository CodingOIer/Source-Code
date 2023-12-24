#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int cnt;
int tree[MaxN * 4];
int lazy[MaxN * 4];
bool use[MaxN];
std::vector<std::pair<int, int>> kill[MaxN];
void pushDown(int root, int s, int t)
{
    if (lazy[root] != 0)
    {
        tree[root * 2] += lazy[root];
        tree[root * 2 + 1] += lazy[root];
        lazy[root * 2] += lazy[root];
        lazy[root * 2 + 1] += lazy[root];
        lazy[root] = 0;
    }
}
void change(int root, int s, int t, int l, int r, int val)
{
    if (l <= s && t <= r)
    {
        tree[root] += val;
        lazy[root] += val;
        return;
    }
    pushDown(root, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(root * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change(root * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[root] = std::max(tree[root * 2], tree[root * 2 + 1]);
}
int query(int root, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[root];
    }
    pushDown(root, s, t);
    int res = 0;
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        res = std::max(res, query(root * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        res = std::max(res, query(root * 2 + 1, mid + 1, t, l, r));
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int t, x;
        scanf("%d%d", &t, &x);
        if (t == 1)
        {
            cnt++;
            kill[x].push_back({i, cnt});
        }
        else if (t == 2)
        {
            if (kill[x].empty())
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                int last = kill[x][kill[x].size() - 1].first;
                use[kill[x][kill[x].size() - 1].second] = true;
                kill[x].pop_back();
                change(1, 1, n, last, i, 1);
            }
        }
    }
    printf("%d\n", query(1, 1, n, 1, n));
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d ", use[i] ? 1 : 0);
    }
    printf("\n");
    return 0;
}