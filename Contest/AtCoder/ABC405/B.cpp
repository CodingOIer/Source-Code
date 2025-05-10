#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, m;
int p[MaxN];
bool vis[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        cnt += vis[p[i]] ? 0 : 1;
        vis[p[i]] = true;
        if (cnt == m)
        {
            printf("%d\n", n - i + 1);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}