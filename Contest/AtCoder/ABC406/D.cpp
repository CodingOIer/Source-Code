#include <cstdio>
#include <map>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int h, w, n, q;
std::vector<int> rx[MaxN];
std::vector<int> ry[MaxN];
std::map<std::tuple<int, int>, bool> map;
int main()
{
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        rx[x].push_back(y);
        ry[y].push_back(x);
        map[{x, y}] = true;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x;
            scanf("%d", &x);
            int answer = 0;
            for (const auto &y : rx[x])
            {
                if (map[{x, y}])
                {
                    answer++;
                }
                map[{x, y}] = false;
            }
            rx[x].clear();
            printf("%d\n", answer);
        }
        else if (op == 2)
        {
            int y;
            scanf("%d", &y);
            int answer = 0;
            for (const auto &x : ry[y])
            {
                if (map[{x, y}])
                {
                    answer++;
                }
                map[{x, y}] = false;
            }
            ry[y].clear();
            printf("%d\n", answer);
        }
    }
    return 0;
}