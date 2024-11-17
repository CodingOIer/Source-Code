#include <cstdio>
#include <cstring>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n, k;
char s[MaxN];
std::vector<std::tuple<int, int, char>> v;
int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    int l, r;
    l = 1;
    r = 1;
    for (int i = 2; i <= n; i++)
    {
        if (s[i] != s[i - 1])
        {
            v.push_back({l, r, s[i - 1]});
            l = r = i;
        }
        else
        {
            r = i;
        }
    }
    v.push_back({l, r, s[n]});
    auto pre = v.begin();
    auto cur = v.begin();
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (std::get<2>(*it) == '1')
        {
            k--;
            cur = it;
            if (k == 0)
            {
                break;
            }
            pre = it;
        }
    }
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (it == cur)
        {
            continue;
        }
        for (int j = std::get<0>(*it); j <= std::get<1>(*it); j++)
        {
            printf("%c", std::get<2>(*it));
        }
        if (it == pre)
        {
            for (int j = std::get<0>(*cur); j <= std::get<1>(*cur); j++)
            {
                printf("%c", std::get<2>(*cur));
            }
        }
    }
    return 0;
}
