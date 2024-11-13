#include <algorithm>
#include <cstdio>
#include <set>
constexpr int MaxN = 2e5 + 5;
int n, m;
int p[MaxN];
std::set<int> set[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        set[i].insert(0x3f3f3f3f);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        int l, r;
        if (p[i] >= 0)
        {
            l = 1;
        }
        else
        {
            l = (-p[i] + i - 1) / i;
        }
        r = std::min(m, (n - p[i] + i - 1) / i);
        for (int j = l; j <= r; j++)
        {
            set[j].insert(i * j + p[i]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int cnt = 0;
        for (auto val : set[i])
        {
            if (cnt != val)
            {
                printf("%d\n", cnt);
                break;
            }
            cnt++;
        }
    }
    return 0;
}