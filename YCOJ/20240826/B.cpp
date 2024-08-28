#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e2 + 5;
int n, m, k;
int board[MaxN][MaxN];
void print()
{
    std::vector<std::tuple<int, int>> p1;
    std::vector<std::tuple<int, int>> p2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == 1)
            {
                p1.push_back({i, j});
            }
            else if (board[i][j] == 2)
            {
                p2.push_back({i, j});
            }
        }
    }
    if (p1.size() < p2.size())
    {
        std::swap(p1, p2);
    }
    for (int i = 0; i < p2.size(); i++)
    {
        int x, y;
        std::tie(x, y) = p1[i];
        printf("%d %d\n", x, y);
        std::tie(x, y) = p2[i];
        printf("%d %d\n", x, y);
    }
    if (p1.size() > p2.size())
    {
        int x, y;
        std::tie(x, y) = p1[p1.size() - 1];
        printf("%d %d\n", x, y);
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if (k == 1)
    {
        printf("-1\n");
        return 0;
    }
    else if (k == 2)
    {
        if (n == 1)
        {
            for (int i = 1; i <= m; i++)
            {
                printf("1 %d\n", i);
            }
        }
        else if (m == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d 1\n", i);
            }
        }
        else
        {
            printf("-1\n");
        }
        return 0;
    }
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        int v = start;
        for (int j = 1; j <= m; j++)
        {
            if (j % 2 == 0)
            {
                v ^= 3;
            }
            board[i][j] = v;
        }
        start ^= 3;
    }
    print();
    return 0;
}