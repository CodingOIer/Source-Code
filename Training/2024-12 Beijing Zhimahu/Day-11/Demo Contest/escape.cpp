#include <cstdio>
constexpr int MaxK = 7e3 + 5;
constexpr long long Mod = 998'244'353;
int n, k;
int p[MaxK];
int main()
{
    scanf("%d%d", &n, &k);
    long long answer = 1;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &p[i]);
        answer = answer * p[i] % Mod;
    }
    printf("%lld\n", answer);
    return 0;
}
