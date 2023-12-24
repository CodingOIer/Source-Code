#include <iostream>
#include <vector>

const int MOD = 998244353;

int main()
{
    int N, X;
    std::cin >> N >> X;
    std::vector<int> T(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> T[i];
    }

    std::vector<int> dp(X + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = X; j >= 0; --j)
        {
            if (j >= T[i])
            {
                dp[j] = (dp[j] + dp[j - T[i]]) % MOD;
            }
        }
    }

    int total_ways = 0;
    for (int i = 1; i <= X; ++i)
    {
        total_ways = (total_ways + dp[i]) % MOD;
    }

    int numerator = dp[X];
    int denominator = total_ways;

    // Compute the modular inverse using extended Euclidean algorithm
    int a = denominator, b = MOD;
    int x = 0, y = 1;
    while (a != 0)
    {
        int t = a;
        a = b % a;
        b = t;
        t = x;
        x = y - (b / t) * x;
        y = t;
    }

    if (x < 0)
    {
        x += MOD;
    }

    int result = (1LL * numerator * x) % MOD;
    std::cout << result << std::endl;

    return 0;
}
