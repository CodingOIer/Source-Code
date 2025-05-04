#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 1e1 + 5;
int n, m;
int sta[MaxN];
long long vis[MaxN];
std::vector<int> v[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &vis[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int c;
        scanf("%d", &c);
        for (int j = 1; j <= c; j++)
        {
            int x;
            scanf("%d", &x);
            v[x].push_back(i);
        }
    }
    long long answer = 0x7f7f7f7f'7f7f7f7f;
    for (int j = 0; j < pow(3, n); j++)
    {
        long long temp = 0;
        int cp = j;
        for (int i = 1; i <= n; i++)
        {
            sta[i] = cp % 3;
            cp /= 3;
            temp += vis[i] * sta[i];
        }
        std::map<int, int> map;
        for (int i = 1; i <= n; i++)
        {
            for (const auto &val : v[i])
            {
                for (int c = 1; c <= sta[i]; c++)
                {
                    map[val]++;
                }
            }
        }
        bool suc = true;
        for (int i = 1; i <= m; i++)
        {
            suc &= map[i] >= 2;
        }
        if (suc)
        {
            answer = std::min(answer, temp);
        }
    }
    printf("%lld\n", answer);
    return 0;
}