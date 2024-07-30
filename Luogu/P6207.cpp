#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <vector>
constexpr int MaxN = 1.2e2 + 5;
int r, c;
char s[MaxN][MaxN];
bool vis[MaxN][MaxN];
std::vector<std::tuple<int, int>> stack;
void dfs(int x, int y)
{
    if (!(1 <= x && x <= r && 1 <= y && y <= c) || s[x][y] == '*' || vis[x][y])
    {
        return;
    }
    vis[x][y] = true;
    stack.push_back({x, y});
    if (x == r && y == c)
    {
        for (auto [x, y] : stack)
        {
            printf("%d %d\n", x, y);
        }
        exit(0);
    }
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
    vis[x][y] = false;
    stack.pop_back();
}
int main()
{
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
    {
        scanf("%s", s[i] + 1);
    }
    dfs(1, 1);
    return 0;
}