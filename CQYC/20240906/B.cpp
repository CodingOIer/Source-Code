#include <cstdio>
constexpr int MaxN = 1e7 + 5;
int n;
int Mod;
int fact[MaxN];
int main()
{
    scanf("%d%d", &n, &Mod);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = 1ll * fact[i - 1] * i % Mod;
    }
    long long answer = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int d = 1; d <= n; d++)
        {
        }
    }
    return 0;
}