#include <cstdio>
#include <map>
#include <numeric>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int a, b, p;
int ref[MaxN];
bool vis[MaxN];
std::map<int, bool> map;
int find(int u)
{
    return ref[u] == u ? u : ref[u] = find(ref[u]);
}
void merge(int u, int v)
{
    if (find(u) == find(v))
    {
        return;
    }
    ref[find(v)] = find(u);
}
int main()
{
    scanf("%d%d%d", &a, &b, &p);
    std::iota(ref + a, ref + 1 + b, a);
    for (int i = 2; i <= b; i++)
    {
        if (vis[i])
        {
            continue;
        }
        std::vector<int> block;
        for (int j = i; j <= b; j += i)
        {
            vis[j] = true;
            if (p <= i && a <= j && j <= b)
            {
                block.push_back(j);
            }
        }
        int last = -1;
        for (const auto &val : block)
        {
            if (last != -1)
            {
                merge(last, val);
            }
            last = val;
        }
    }
    for (int i = a; i <= b; i++)
    {
        map[find(i)] = true;
    }
    printf("%zu\n", map.size());
    return 0;
}
