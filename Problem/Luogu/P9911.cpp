#include <algorithm>
#include <cstdio>
constexpr int MaxN = 3e3 + 5;
int n;
int p[MaxN];
bool vis[MaxN];
std::pair<int, int> m[MaxN][MaxN];
std::pair<int, int> dfs(int l, int r)
{
    if (m[l][r] != std::make_pair(-1, -1))
    {
        return m[l][r];
    }
    if (l == r)
    {
        if (!vis[p[l]])
        {
            m[l][r] = {1, 0};
            return {1, 0};
        }
        else
        {
            m[l][r] = {0, 0};
            return {0, 0};
        }
    }
    std::pair<int, int> left, right;
    if (!vis[p[l]])
    {
        vis[p[l]] = true;
        left = dfs(l + 1, r);
        vis[p[l]] = false;
    }
    else
    {
        left = dfs(l + 1, r);
    }
    std::swap(left.first, left.second);
    left.first += (!vis[p[l]] ? 1 : 0);
    if (!vis[p[r]])
    {
        vis[p[r]] = true;
        right = dfs(l, r - 1);
        vis[p[r]] = false;
    }
    else
    {
        right = dfs(l, r - 1);
    }
    std::swap(right.first, right.second);
    right.first += (!vis[p[r]] ? 1 : 0);
    if (left.first - left.second > right.first - right.second)
    {

        m[l][r] = left;
        return left;
    }
    else
    {
        m[l][r] = right;
        return right;
    }
}
int main()
{
    scanf("%d", &n);
    int max_color = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        max_color = p[i] > max_color ? p[i] : max_color;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            m[i][j] = {-1, -1};
        }
    }
    auto res = dfs(1, n);
    printf("%d:%d\n", res.first, res.second);
    return 0;
}