#include <cstdio>
#include <numeric>
#include <set>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n;
int dnaId;
int fd[MaxN];
std::set<std::tuple<int, int, int>> set;
inline int find(int x)
{
    return x == 0 ? x : fd[x] == x ? x : find(fd[x]);
}
inline void refto(int x, int y)
{
    if (x == 0)
    {
        return;
    }
    fd[find(x)] = y;
}
int main()
{
    scanf("%d", &n);
    set.insert({1, 1e9, 0});
    std::iota(fd + 1, fd + 1 + n, 1);
    for (int i = 1; i <= n; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            dnaId++;
            auto it = set.upper_bound({a, 0x7f7f7f7f, 0x7f7f7f7f});
            it--;
            auto cp = it;
            std::vector<std::tuple<int, int, int>> v;
            for (; cp != set.end() && std::get<0>(*cp) <= b;)
            {
                v.push_back(*cp);
                refto(std::get<2>(*cp), dnaId);
                cp++;
            }
            for (const auto &k : v)
            {
                set.erase(k);
                if (std::get<0>(k) < a)
                {
                    set.insert({std::get<0>(k), a - 1, std::get<2>(k)});
                }
                if (b < std::get<1>(k))
                {
                    set.insert({b + 1, std::get<1>(k), std::get<2>(k)});
                }
            }
            set.insert({a, b, dnaId});
            it = set.upper_bound({c, 0x7f7f7f7f, 0x7f7f7f7f});
            it--;
            cp = it;
            v.clear();
            for (; cp != set.end() && std::get<0>(*cp) <= d;)
            {
                v.push_back(*cp);
                refto(std::get<2>(*cp), dnaId);
                cp++;
            }
            for (const auto &k : v)
            {
                set.erase(k);
                if (std::get<0>(k) < c)
                {
                    set.insert({std::get<0>(k), c - 1, std::get<2>(k)});
                }
                if (d < std::get<1>(k))
                {
                    set.insert({d + 1, std::get<1>(k), std::get<2>(k)});
                }
            }
            set.insert({c, d, dnaId});
        }
        else if (op == 2)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == y)
            {
                printf("Yes\n");
                continue;
            }
            auto itx = set.upper_bound({x, 0x7f7f7f7f, 0x7f7f7f7f});
            itx--;
            auto ity = set.upper_bound({y, 0x7f7f7f7f, 0x7f7f7f7f});
            ity--;
            int fx, fy;
            fx = find(std::get<2>(*itx));
            fy = find(std::get<2>(*ity));
            printf("%s\n", fx != 0 && fy != 0 && fx == fy ? "Yes" : "No");
        }
    }
    return 0;
}
