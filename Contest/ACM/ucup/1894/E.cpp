#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m, k;
int w[MaxN];
bool rd;
char s[MaxN];
std::vector<int> begin;
std::vector<std::vector<int>> v;
void calc()
{
    int allCost = 0;
    int accepted = 0;
    std::vector<std::tuple<int, int>> c;
    for (int i = 1; i <= m - 1; i++)
    {
        if (w[i] == 0)
        {
            int fail = 0;
            bool first = true;
            for (const auto &val : v[i])
            {
                if (!first && fail == 0 && val == 0)
                {
                    return;
                }
                first = false;
                fail = fail * 10 + val;
            }
            if (!(1 <= fail && fail <= 100) || (fail == 1 ^ s[begin[i] + int(v[i].size()) + 2] == 'y'))
            {
                return;
            }
            c.push_back({-1, fail});
        }
        else
        {
            int cost, fail;
            cost = fail = 0;
            bool first = true;
            for (int j = 0; j < int(v[i].size()) - w[i]; j++)
            {
                if (!first && cost == 0 && v[i][j] == 0)
                {
                    return;
                }
                first = false;
                cost = cost * 10 + v[i][j];
            }
            first = true;
            for (int j = int(v[i].size()) - w[i]; j < int(v[i].size()); j++)
            {
                if (!first && fail == 0 && v[i][j] == 0)
                {
                    return;
                }
                first = false;
                fail = fail * 10 + v[i][j];
            }
            if (!(1 <= fail && fail <= 100) || !(0 <= cost && cost <= 299) ||
                (fail == 1 ^ s[begin[i] + int(v[i].size()) + 2] == 'y'))
            {
                return;
            }
            c.push_back({cost, fail});
            allCost += cost + (fail - 1) * 20;
            accepted++;
        }
    }
    int g = 1;
    for (; s[g] != 't'; g++)
    {
    }
    g--;
    long long realAccepted, realCost, cost, fail;
    for (int i = 1; i <= std::min(2, g - 1); i++)
    {
        for (int j = std::max(i + 1, g - 3); j <= g - 1; j++)
        {
            realAccepted = 0;
            realCost = 0;
            fail = 0;
            bool first = true;
            for (int o = 1; o <= i; o++)
            {
                if (!first && realAccepted == 0 && (s[o] ^ 48) == 0)
                {
                    return;
                }
                first = false;
                realAccepted = realAccepted * 10 + (s[o] ^ 48);
            }
            first = true;
            for (int o = i + 1; o <= j; o++)
            {
                if (!first && realCost == 0 && (s[o] ^ 48) == 0)
                {
                    return;
                }
                first = false;
                realCost = realCost * 10 + (s[o] ^ 48);
            }
            first = true;
            for (int o = j + 1; o <= g; o++)
            {
                if (!first && fail == 0 && (s[o] ^ 48) == 0)
                {
                    return;
                }
                first = false;
                fail = fail * 10 + (s[o] ^ 48);
            }
            if (!(1 <= fail && fail <= 100) || (fail == 1 ^ s[g + 3] == 'y') || realAccepted != accepted ||
                realCost != allCost)
            {
                continue;
            }
            printf("%d %d %lld", accepted, allCost, fail);
            if (fail == 1)
            {
                printf(" try");
            }
            else
            {
                printf(" tries");
            }
            for (const auto &[cost, fail] : c)
            {
                if (cost != -1)
                {
                    printf(" %d", cost);
                }
                if (fail == 1)
                {
                    printf(" %d try", fail);
                }
                else
                {
                    printf(" %d tries", fail);
                }
            }
            printf("\n");
            rd = true;
            return;
        }
    }
    for (int i = 1; i <= std::min(2, g - 1); i++)
    {
        for (int j = i + 1; j <= std::min(i + 5, g - 1); j++)
        {
            for (int l = std::max(j + 1, g - 3); l <= g - 1; l++)
            {
                realAccepted = 0;
                realCost = 0;
                cost = 0;
                fail = 0;
                bool first = true;
                for (int o = 1; o <= i; o++)
                {
                    if (!first && realAccepted == 0 && (s[o] ^ 48) == 0)
                    {
                        return;
                    }
                    first = false;
                    realAccepted = realAccepted * 10 + (s[o] ^ 48);
                }
                first = true;
                for (int o = i + 1; o <= j; o++)
                {
                    if (!first && realCost == 0 && (s[o] ^ 48) == 0)
                    {
                        return;
                    }
                    first = false;
                    realCost = realCost * 10 + (s[o] ^ 48);
                }
                first = true;
                for (int o = j + 1; o <= l; o++)
                {
                    if (!first && cost == 0 && (s[o] ^ 48) == 0)
                    {
                        return;
                    }
                    first = false;
                    cost = cost * 10 + (s[o] ^ 48);
                }
                first = true;
                for (int o = l + 1; o <= g; o++)
                {
                    if (!first && fail == 0 && (s[o] ^ 48) == 0)
                    {
                        return;
                    }
                    first = false;
                    fail = fail * 10 + (s[o] ^ 48);
                }
                if (!(1 <= fail && fail <= 100) || !(0 <= cost && cost <= 299) || (fail == 1 ^ s[g + 3] == 'y') ||
                    realAccepted != accepted + 1 || realCost != allCost + cost + (fail - 1) * 20)
                {
                    continue;
                }
                printf("%lld %lld %lld %lld", realAccepted, realCost, cost, fail);
                if (fail == 1)
                {
                    printf(" try");
                }
                else
                {
                    printf(" tries");
                }
                for (const auto &[cost, fail] : c)
                {
                    if (cost != -1)
                    {
                        printf(" %d", cost);
                    }
                    if (fail == 1)
                    {
                        printf(" %d try", fail);
                    }
                    else
                    {
                        printf(" %d tries", fail);
                    }
                }
                printf("\n");
                rd = true;
            }
        }
    }
}
void dfs(int u)
{
    if (u == m)
    {
        calc();
        return;
    }
    if (rd)
    {
        return;
    }
    for (int i = 0; i <= std::min(int(v[u].size()), 3); i++)
    {
        w[u] = i;
        dfs(u + 1);
        if (rd)
        {
            return;
        }
    }
}
void solve()
{
    rd = false;
    v.clear();
    begin.clear();
    scanf("%s", s + 1);
    k = strlen(s + 1);
    m = 0;
    std::vector<int> prefix;
    begin.push_back(0);
    for (int i = 1; i <= k; i++)
    {
        if (s[i] == 't')
        {
            v.push_back(prefix);
            prefix.clear();
            m++;
        }
        if (std::isdigit(s[i]) && m >= 1)
        {
            if (prefix.empty())
            {
                begin.push_back(i);
            }
            prefix.push_back(s[i] ^ 48);
        }
    }
    dfs(1);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        solve();
    }
    return 0;
}
