#include <cstdio>
#include <vector>
const int MaxN = 3e5 + 5;
const int MaxK = 3e1 + 5;
const long long Mod = 998244353;
int n, m;
long long power[MaxN][MaxK];
std::vector<int> link[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        power[i][0] = 1;
        for (int j = 1; j <= 30; j++)
        {
            power[i][j] = power[i][j - 1] % Mod;
        }
    }
    return 0;
}