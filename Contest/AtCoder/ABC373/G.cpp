#include <cstdio>
#include <queue>
#include <utility>
constexpr int MaxN = 3e2 + 5;
#define int long long
int n, p[MaxN];
std::pair<int, int> a[MaxN], b[MaxN];
std::queue<int> bfs;

int aaa(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> p3)
{
    int x1 = p2.first - p1.first;
    int y1 = p2.second - p1.second;
    int x2 = p3.first - p1.first;
    int y2 = p3.second - p1.second;
    return x1 * y2 - x2 * y1;
}
bool bb(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, std::pair<int, int> d)
{
    int d1 = aaa(a, b, c);
    int d2 = aaa(a, b, d);
    int d3 = aaa(c, d, a);
    int d4 = aaa(c, d, b);
    return d1 * d2 < 0 && d3 * d4 < 0;
}

signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i].first, &a[i].second);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &b[i].first, &b[i].second);
    for (int i = 1; i <= n; i++)
    {
        for (p[i] = i, bfs.push(i); bfs.size(); bfs.pop())
        {
            int x = bfs.front();
            for (int j = 1; j <= i; j++)
            {
                if (j != x)
                {
                    if (bb(a[x], b[p[x]], a[j], b[p[j]]))
                    {
                        std::swap(p[x], p[j]), bfs.push(j), bfs.push(x);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", p[i]);
    }
    return 0;
}