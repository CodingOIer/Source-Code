#include <cstdio>
#include <map>
constexpr int MaxN = 1e3 + 5;
int n, m, k;
int answer[MaxN];
int p[MaxN][MaxN];
std::map<int, bool> map;
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        map.clear();
        for (int j = 1; j <= n; j++)
        {
            map[p[j][i]] = true;
        }
        for (auto k : map)
        {
            answer[k.first]++;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}