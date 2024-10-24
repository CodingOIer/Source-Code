#include <cstdio>
#include <map>
#include <tuple>
int n, q;
std::map<std::tuple<int, int>, bool> map;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            map[{x, y}] = true;
        }
        else if (op == 2)
        {
            map[{x, y}] = false;
        }
        else
        {
            printf("%s\n", map[{x, y}] && map[{y, x}] ? "Yes" : "No");
        }
    }
    return 0;
}