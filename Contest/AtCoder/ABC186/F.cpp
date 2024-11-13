#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int h, w, m;
int ln[MaxN];
int col[MaxN];
long long tree[MaxN];
long long answer;
std::vector<int> v[MaxN];
inline void change(int x, int val)
{
    for (; x <= h; x += x & -x)
    {
        tree[x] += val;
    }
}
inline long long query(int x)
{
    long long res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
int main()
{
    scanf("%d%d%d", &h, &w, &m);
    int lh, lw;
    lh = h;
    lw = w;
    for (int i = 1; i <= h; i++)
    {
        ln[i] = w;
    }
    for (int i = 1; i <= w; i++)
    {
        col[i] = h;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ln[x] = std::min(ln[x], y - 1);
        col[y] = std::min(col[y], x - 1);
        if (x == 1)
        {
            lw = std::min(lw, y - 1);
        }
        if (y == 1)
        {
            lh = std::min(lh, x - 1);
        }
    }
    for (int i = lh + 1; i <= h; i++)
    {
        ln[i] = 0;
    }
    for (int i = lw + 1; i <= w; i++)
    {
        col[i] = 0;
    }
    for (int i = 1; i <= w; i++)
    {
        answer += col[i];
    }
    for (int i = 1; i <= h; i++)
    {
        answer += ln[i];
        v[ln[i]].push_back(i);
    }
    for (int i = 1; i <= h; i++)
    {
        change(i, 1);
    }
    for (auto val : v[0])
    {
        change(val, -1);
    }
    for (int i = 1; i <= w; i++)
    {
        answer -= query(col[i]);
        for (auto val : v[i])
        {
            change(val, -1);
        }
    }
    printf("%lld\n", answer);
    return 0;
}