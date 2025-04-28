#include <cstdio>
#include <vector>
constexpr int MaxN = 1e8 + 5;
int n, q;
bool vis[MaxN];
std::vector<int> v;
void init()
{
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        v.push_back(i);
        for (int j = 2 * i; j <= n; j += i)
        {
            vis[j] = true;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    init();
    for (int i = 1; i <= q; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", v[x - 1]);
    }
    return 0;
}