#include <algorithm>
#include <cstdio>
#include <string>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e2 + 5;
constexpr char *Contest = " ABCDE";
int n;
int p[MaxN];
std::vector<std::tuple<int, std::string>> v;
int main()
{
    n = 5;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int j = 1; j < (1 << n); j++)
    {
        int su = 0;
        std::string s;
        for (int i = 1; i <= n; i++)
        {
            if ((j >> (i - 1)) & 1)
            {
                su += p[i];
                s += Contest[i];
            }
        }
        v.push_back({-su, s});
    }
    std::sort(v.begin(), v.end());
    for (const auto &[__ignore, s] : v)
    {
        printf("%s\n", s.c_str());
    }
    return 0;
}
