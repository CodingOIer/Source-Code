#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
class question
{
  public:
    int k;
    int id;
    int l, r;
    question()
    {
        k = 0;
        l = 0;
        r = 0;
        id = 0;
    }
};
int n, m;
int s_len;
int p[MaxN];
int s[MaxN];
int tree[MaxN];
int answer[MaxN];
std::vector<int> w[MaxN];
inline int link(int x)
{
    return std::lower_bound(s + 1, s + 1 + s_len, x) - s;
}
inline int lowerBit(int x)
{
    return x & (-x);
}
inline void change(int x, int val)
{
    for (; x <= n; x += lowerBit(x))
    {
        tree[x] += val;
    }
}
inline int query(int x)
{
    int res = 0;
    for (; x > 0; x -= lowerBit(x))
    {
        res += tree[x];
    }
    return res;
}
inline int query(int l, int r)
{
    return query(r) - query(l - 1);
}
void solve(int l, int r, const std::vector<question> &q)
{
    if (q.empty())
    {
        return;
    }
    if (l == r)
    {
        for (auto x : q)
        {
            answer[x.id] = l;
        }
        return;
    }
    int mid = (l + r) / 2;
    for (int i = l; i <= mid; i++)
    {
        for (auto x : w[i])
        {
            change(x, 1);
        }
    }
    std::vector<question> left;
    std::vector<question> right;
    for (auto x : q)
    {
        int sum = query(x.l, x.r);
        if (x.k <= sum)
        {
            left.push_back(x);
        }
        else
        {
            auto temp = x;
            temp.k -= sum;
            right.push_back(temp);
        }
    }
    for (int i = l; i <= mid; i++)
    {
        for (auto x : w[i])
        {
            change(x, -1);
        }
    }
    solve(l, mid, left);
    solve(mid + 1, r, right);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        s[i] = p[i];
    }
    std::sort(s + 1, s + 1 + n);
    s_len = std::unique(s + 1, s + 1 + n) - s - 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = link(p[i]);
        w[p[i]].push_back(i);
    }
    std::vector<question> q;
    for (int i = 1; i <= m; i++)
    {
        question temp;
        scanf("%d%d%d", &temp.l, &temp.r, &temp.k);
        temp.id = i;
        q.push_back(temp);
    }
    solve(1, s_len, q);
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", s[answer[i]]);
    }
    return 0;
}