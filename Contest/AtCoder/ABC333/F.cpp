#include <iostream>
#include <vector>

const int MOD = 998244353;

long long mod_pow(long long a, long long b)
{
    long long result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<long long> dp(N + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= N; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 1]) % MOD;
    }

    for (int i = 1; i <= N; ++i)
    {
        long long numerator = dp[i];
        long long denominator = mod_pow(2, N);
        long long inverse_denominator = mod_pow(denominator, MOD - 2);
        long long probability = (numerator * inverse_denominator) % MOD;

        std::cout << probability << " ";
    }

    return 0;
}
