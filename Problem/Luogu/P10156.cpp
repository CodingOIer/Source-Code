#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 5e3 + 5;
int n, m, k;
int c[MaxN];
int l[MaxN];
int r[MaxN];
bool out[MaxN];
long long x;
long long p[MaxN];
long long last[MaxN];
long long calc[MaxN];
long long dp[MaxN][MaxN];
std::vector<int> have[MaxN];
std::vector<int> group[MaxN];
std::vector<int> update[MaxN];
std::vector<long long> v;
long long get(int w)
{
    if (l[w] != 0)
    {
        return calc[w];
    }
    long long res = 0x7f7f7f7f7f7f7f7f;
    for (auto i : group[w])
    {
        if (out[i])
        {
            continue;
        }
        for (auto j : group[w])
        {
            if (out[j] || i == j)
            {
                continue;
            }
            auto b = have[w];
            b.push_back(i);
            b.push_back(j);
            std::sort(b.begin(), b.end());
            long long temp = 0;
            for (int k = 0; k + 1 < b.size(); k += 2)
            {
                temp += p[b[k]] + p[b[k + 1]] + x * (b[k + 1] - b[k]);
            }
            if (temp < res)
            {
                res = temp;
                update[w].clear();
                for (auto v : b)
                {
                    update[w].push_back(v);
                }
                l[w] = i;
                r[w] = j;
            }
        }
    }
    calc[w] = res;
    return res;
}
long long add_two()
{
    int w = 0;
    long long res = 0x7f7f7f7f7f7f7f;
    for (int i = 1; i <= k; i++)
    {
        long long r = get(i) - last[i];
        if (r < res)
        {
            w = i;
            res = r;
        }
    }
    last[w] += res;
    have[w].clear();
    out[l[w]] = true;
    out[r[w]] = true;
    for (auto v : update[w])
    {
        have[w].push_back(v);
    }
    l[w] = 0;
    return res;
}
int main()
{
    scanf("%d%d%d%lld", &n, &m, &k, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        group[c[i]].push_back(i);
    }
    int max = 0;
    for (int i = 1; i <= k; i++)
    {
        max += group[i].size() / 2 * 2;
    }
    if (n - max > m)
    {
        printf("Impossible\n");
        return 0;
    }
    if (x == 0)
    {
        for (int i = 1; i <= k; i++)
        {
            std::sort(group[i].begin(), group[i].end(), [](const int &__x, const int &__y) { return p[__x] < p[__y]; });
            for (int j = 0; j + 1 < group[i].size(); j += 2)
            {
                v.push_back(p[group[i][j]] + p[group[i][j + 1]]);
            }
        }
        std::sort(v.begin(), v.end());
        long long answer = 0;
        for (auto x : v)
        {
            if (n <= m)
            {
                break;
            }
            answer += x;
            n -= 2;
        }
        printf("%lld\n", answer);
    }
    else if (n <= 20)
    {
        long long answer = 0x7f7f7f7f7f7f7f7f;
        for (int j = 0; j < (1 << n); j++)
        {
            for (int i = 1; i <= k; i++)
            {
                have[i].clear();
            }
            for (int i = 1; i <= n; i++)
            {
                if (1 & (j >> (i - 1)))
                {
                    have[c[i]].push_back(i);
                }
            }
            int cnt = 0;
            long long temp = 0;
            for (int i = 1; i <= k; i++)
            {
                if (have[i].size() % 2 == 1)
                {
                    temp = 0x7f7f7f7f7f7f7f7f;
                    break;
                }
                cnt += have[i].size();
                for (int k = 0; k + 1 < have[i].size(); k += 2)
                {
                    temp += p[have[i][k]] + p[have[i][k + 1]] + x * (have[i][k + 1] - have[i][k]);
                }
            }
            answer = std::min(answer, n - cnt <= m ? temp : 0x7f7f7f7f7f7f7f7f);
        }
        printf("%lld\n", answer);
    }
    else if (k == 1)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = 0x7f7f7f7f7f7f7f7f;
            }
        }
        dp[1][1] = p[1];
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] =
                    std::min(dp[i - 1][j] + (j % 2 == 1 ? x : 0), dp[i - 1][j - 1] + p[i] + (j % 2 == 0 ? x : 0));
            }
        }
        long long answer = 0x7f7f7f7f7f7f7f7f;
        for (int i = 1; i <= n; i++)
        {
            answer = std::min(answer, dp[i][n - m + (n - m) % 2 == 1 ? 1 : 0]);
        }
        printf("%lld\n", answer);
    }
    else
    {
        long long answer = 0;
        for (; n > m;)
        {
            n -= 2;
            answer += add_two();
        }
        printf("%lld\n", answer);
    }
    return 0;
}