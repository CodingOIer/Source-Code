#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <vector>
constexpr int MaxN = 1.5e3 + 5;
int n, k;
int p[MaxN][MaxN];
bool vis[MaxN * MaxN];
long long answer[MaxN];
std::vector<std::tuple<int, int, int, int>> temp;
std::vector<std::tuple<int, int, int, int>> v[2][MaxN];
int f(int x, int y, int sx, int sy)
{
    return std::max(abs(x - sx), abs(y - sy));
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        v[1][i].push_back({0, 1, i, p[1][i]});
        answer[1]++;
    }
    for (int i = 2; i <= n; i++)
    {
        v[i & 1][1].clear();
        v[i & 1][1].push_back({0, i, 1, p[i][1]});
        answer[1]++;
        for (int j = 2; j <= n; j++)
        {
            temp.clear();
            v[i & 1][j].clear();
            for (const auto &[dis, x, y, color] : v[i & 1][j - 1])
            {
                temp.push_back({f(x, y, i, j), x, y, color});
            }
            for (const auto &[dis, x, y, color] : v[~i & 1][j])
            {
                temp.push_back({f(x, y, i, j), x, y, color});
            }
            for (const auto &[dis, x, y, color] : v[~i & 1][j - 1])
            {
                temp.push_back({f(x, y, i, j), x, y, color});
            }
            temp.push_back({0, i, j, p[i][j]});
            std::sort(temp.begin(), temp.end());
            int len = 1;
            for (const auto &[dis, x, y, color] : temp)
            {
                if (vis[color])
                {
                    continue;
                }
                vis[color] = true;
                v[i & 1][j].push_back({dis, x, y, color});
                len = dis;
                if (int(v[i & 1][j].size()) > k)
                {
                    break;
                }
            }
            if (int(v[i & 1][j].size()) <= k)
            {
                len = std::min(i, j);
            }
            len = std::min({len, i, j});
            answer[len]++;
            for (const auto &[dis, x, y, color] : v[i & 1][j])
            {
                vis[color] = false;
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        answer[i] += answer[i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", answer[i]);
    }
    return 0;
}
