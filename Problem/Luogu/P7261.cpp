#include <algorithm>
#include <cstdio>
#include <random>
#include <vector>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 5e5 + 5;
constexpr int MaxRandomTryCount = 30;
int n, c, m;
int p[MaxN];
std::vector<int> v[MaxN];
int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        v[p[i]].push_back(i);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int answer = -1;
        for (int _ = 1; _ <= MaxRandomTryCount; _++)
        {
            int color = p[rnd() % (r - l + 1) + l];
            int cnt = std::upper_bound(v[color].begin(), v[color].end(), r) -
                      std::lower_bound(v[color].begin(), v[color].end(), l);
            if (cnt > (r - l + 1) / 2)
            {
                answer = color;
                break;
            }
        }
        if (answer == -1)
        {
            printf("no\n");
        }
        else
        {
            printf("yes %d\n", answer);
        }
    }
    return 0;
}