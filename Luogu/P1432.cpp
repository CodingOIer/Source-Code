#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
int a, b, n;
std::map<std::tuple<int, int>, bool> map;
std::queue<std::tuple<int, int, std::vector<int>>> queue;
inline void A(int x, int y, std::vector<int> &v) // fill A
{
    x = a;
    if (map[{x, y}])
    {
        return;
    }
    map[{x, y}] = true;
    v.push_back(1);
    queue.push({x, y, v});
    v.pop_back();
}
inline void B(int x, int y, std::vector<int> &v) // fill B
{
    y = b;
    if (map[{x, y}])
    {
        return;
    }
    map[{x, y}] = true;
    v.push_back(2);
    queue.push({x, y, v});
    v.pop_back();
}
inline void C(int x, int y, std::vector<int> &v) // empty A
{
    x = 0;
    if (map[{x, y}])
    {
        return;
    }
    map[{x, y}] = true;
    v.push_back(3);
    queue.push({x, y, v});
    v.pop_back();
}
inline void D(int x, int y, std::vector<int> &v) // empty B
{
    y = 0;
    if (map[{x, y}])
    {
        return;
    }
    map[{x, y}] = true;
    v.push_back(4);
    queue.push({x, y, v});
    v.pop_back();
}
inline void E(int x, int y, std::vector<int> &v) // pour B to A
{
    int g = std::min(a - x, y);
    x += g;
    y -= g;
    if (map[{x, y}])
    {
        return;
    }
    map[{x, y}] = true;
    v.push_back(5);
    queue.push({x, y, v});
    v.pop_back();
}
inline void F(int x, int y, std::vector<int> &v) // pour A to B
{
    int g = std::min(x, b - y);
    x -= g;
    y += g;
    if (map[{x, y}])
    {
        return;
    }
    map[{x, y}] = true;
    v.push_back(6);
    queue.push({x, y, v});
    v.pop_back();
}
void solve()
{
    scanf("%d%d%d", &a, &b, &n);
    map.clear();
    for (; !queue.empty();)
    {
        queue.pop();
    }
    queue.push({0, 0, {}});
    map[{0, 0}] = true;
    for (;;)
    {
        auto [x, y, v] = queue.front();
        queue.pop();
        if (y == n)
        {
            printf("%zu", v.size());
            for (auto x : v)
            {
                printf(" %d", x);
            }
            printf("\n");
            break;
        }
        A(x, y, v);
        B(x, y, v);
        C(x, y, v);
        D(x, y, v);
        E(x, y, v);
        F(x, y, v);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}