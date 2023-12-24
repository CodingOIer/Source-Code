#include <cmath>
#include <iostream>
#include <vector>

const long long MOD = 998244353;

long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main()
{
    long long A, B;
    std::cin >> A >> B;

    std::vector<long long> divisors;

    for (long long i = 1; i <= std::sqrt(A); ++i)
    {
        if (A % i == 0)
        {
            divisors.push_back(i);
            if (i != A / i)
            {
                divisors.push_back(A / i);
            }
        }
    }

    long long result = 1;
    for (const long long &divisor : divisors)
    {
        long long exp = 0;
        long long temp = A;
        while (temp % divisor == 0)
        {
            temp /= divisor;
            exp++;
        }
        result = (result * (exp * B + 1)) % MOD;
    }

    std::cout << result << std::endl;
    return 0;
}
