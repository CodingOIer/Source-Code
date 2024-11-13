#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 5e2 + 5;
constexpr int MaxM = 6e4 + 5;
constexpr int MaxL = 2.5e5 + 5;
class question
{
  public:
    int k;
    int id;
    int sx, sy;
    int ex, ey;
    question()
    {
        k = 0;
        id = 0;
        sx = 0;
        sy = 0;
        ex = 0;
        ey = 0;
    }
};
int n, m;
int s_len;
int s[MaxL];
int p[MaxN][MaxN];
int tree[MaxN][MaxN];
int answer[MaxM];
std::vector<std::pair<int, int>> w[MaxL];
inline int link(int x)
{
    return std::lower_bound(s + 1, s + 1 + s_len, x) - s;
}
inline int lowerBit(int x)
{
    return x & (-x);
}
inline void change(int x, int y, int val)
{
    for (; x <= n; x += lowerBit(x))
    {
        for (int i = y; i <= n; i += lowerBit(i))
        {
            tree[x][i] += val;
        }
    }
}
inline int query(int x, int y)
{
    int res = 0;
    for (; x > 0; x -= lowerBit(x))
    {
        for (int i = y; i > 0; i -= lowerBit(i))
        {
            res += tree[x][i];
        }
    }
    return res;
}
inline int query(int sx, int sy, int ex, int ey)
{
    return query(ex, ey) - query(ex, sy - 1) - query(sx - 1, ey) + query(sx - 1, sy - 1);
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
            change(x.first, x.second, 1);
        }
    }
    std::vector<question> left;
    std::vector<question> right;
    for (auto x : q)
    {
        int sum = query(x.sx, x.sy, x.ex, x.ey);
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
            change(x.first, x.second, -1);
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
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &p[i][j]);
            s[(i - 1) * n + j] = p[i][j];
        }
    }
    std::sort(s + 1, s + 1 + n * n);
    s_len = std::unique(s + 1, s + 1 + n * n) - s - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = link(p[i][j]);
            w[p[i][j]].push_back({i, j});
        }
    }
    std::vector<question> q;
    for (int i = 1; i <= m; i++)
    {
        question temp;
        scanf("%d%d%d%d%d", &temp.sx, &temp.sy, &temp.ex, &temp.ey, &temp.k);
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