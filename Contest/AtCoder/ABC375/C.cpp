#include <algorithm>
#include <cstdio>
#include <tuple>
constexpr int MaxN = 3e3 + 5;
int n;
char s[MaxN][MaxN];
char t[MaxN][MaxN];
std::tuple<int, int> f(std::tuple<int, int> x)
{
    return {std::get<1>(x), n + 1 - std::get<0>(x)};
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cnt = std::min(std::min(n - i + 1, i), std::min(n - j + 1, j)) % 4;
            int x, y;
            std::tuple<int, int> k;
            k = {i, j};
            for (int _ = 1; _ <= cnt; _++)
            {
                k = f(k);
            }
            x = std::get<0>(k);
            y = std::get<1>(k);
            t[x][y] = s[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%s\n", t[i] + 1);
    }
    return 0;
}