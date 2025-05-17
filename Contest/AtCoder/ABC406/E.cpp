#include <cstdio>
const int MaxN = 65;
const int Mod = 998244353;
long long n, k;
long long answer;
long long preSum;
long long fact[MaxN];
long long pow2[MaxN];
long long invFact[MaxN];
long long C[MaxN][MaxN];
long long fsp(long long x, long long y = Mod - 2)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res = res * x % Mod;
        }
        x = x * x % Mod;
        y >>= 1;
    }
    return res;
}
void init()
{
    fact[0] = 1;
    for (int i = 1; i < MaxN; i++)
    {
        fact[i] = fact[i - 1] * i % Mod;
    }
    invFact[MaxN - 1] = fsp(fact[MaxN - 1]);
    for (int i = MaxN - 1; i > 0; i--)
    {
        invFact[i - 1] = invFact[i] * i % Mod;
    }
    for (int n = 0; n < MaxN; n++)
    {
        for (int m = 0; m <= n; m++)
        {
            C[n][m] = fact[n] * invFact[m] % Mod * invFact[n - m] % Mod;
        }
    }
    pow2[0] = 1;
    for (int i = 1; i < MaxN; i++)
    {
        pow2[i] = pow2[i - 1] * 2 % Mod;
    }
}
void solve()
{
    answer = 0;
    preSum = 0;
    int cnt = 0;
    int top = -1;
    scanf("%lld%lld", &n, &k);
    for (int i = 63; i >= 0; i--)
    {
        if ((n >> i) & 1ULL)
        {
            top = i;
            break;
        }
    }
    for (int i = top; i >= 0; i--)
    {
        if ((n >> i) & 1)
        {
            int cp = i;
            int need = k - cnt;
            if (need >= 0 && need <= cp)
            {
                long long ways = C[cp][need];
                answer = (answer + preSum * ways) % Mod;
                if (need > 0)
                {
                    long long part = C[cp - 1][need - 1] * ((pow2[cp] - 1 + Mod) % Mod) % Mod;
                    answer = (answer + part) % Mod;
                }
            }
            cnt++;
            preSum = (preSum + pow2[i]) % Mod;
        }
    }
    if (cnt == k)
    {
        answer = (answer + (long long)(n % Mod)) % Mod;
    }
    printf("%lld\n", answer);
}
int main()
{
    init();
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
