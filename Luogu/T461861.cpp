#include <cstdio>
#include <utility>
#include <vector>
constexpr int MaxN = 5e3 + 5;
constexpr int MaxM = 2e6 + 5;
class unordered_map
{
    int p[2][MaxM];

  public:
    int &operator[](int x)
    {
        if (x >= 0)
        {
            return p[0][x];
        }
        else
        {
            return p[1][-x];
        }
    }
};
int n, q, b;
int p[MaxN];
long long s[MaxN][MaxN];
unordered_map map;
std::vector<std::pair<int, int>> list[MaxN];
inline int calc(int x)
{
    if (1 <= x && x <= n)
    {
        return (x - 1) / b + 1;
    }
    return b + 5;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = i + 1; k <= n; k++)
        {
            if (map[-(p[i] + p[k])] != 0)
            {
                list[i].push_back({k, map[-(p[i] + p[k])]});
            }
            map[p[k]]++;
        }
        for (int j = i + 1; j <= n; j++)
        {
            map[p[j]]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : list[i])
        {
            s[i][x.first] += x.second;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", s[y][y] - s[x - 1][y] - s[y][x - 1] + s[x - 1][x - 1]);
    }
    return 0;
}