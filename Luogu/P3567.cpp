#include <algorithm>
#include <cstdio>
#include <random>
#include <unordered_map>
#include <vector>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 5e5 + 5;
constexpr int MaxRandom = 20;
int n, m;
int p[MaxN];
int s[MaxN];
int link[MaxN];
std::vector<int> meet[MaxN];
std::unordered_map<int, bool> cnt;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        s[i] = p[i];
    }
    std::sort(s + 1, s + 1 + n);
    int len = std::unique(s + 1, s + 1 + n) - s - 1;
    for (int i = 1; i <= n; i++)
    {
        int w = std::lower_bound(s + 1, s + 1 + len, p[i]) - s;
        link[w] = p[i];
        p[i] = w;
    }
    for (int i = 1; i <= n; i++)
    {
        meet[p[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int res = 0;
        for (int j = 1; j <= MaxRandom; j++)
        {
            int k = rnd() % (r - l + 1) + l;
            int want = p[k];
            if ((int)(meet[want].size()) < (r - l + 1) / 2 + 1 || cnt[want])
            {
                continue;
            }
            int le = std::lower_bound(meet[want].begin(), meet[want].end(), l) - meet[want].begin() + 1;
            int ri = std::upper_bound(meet[want].begin(), meet[want].end(), r) - meet[want].begin();
            if ((ri - le + 1) >= (r - l + 1) / 2 + 1)
            {
                res = want;
                break;
            }
            cnt[want] = true;
        }
        cnt.clear();
        printf("%d\n", link[res]);
    }
    return 0;
}