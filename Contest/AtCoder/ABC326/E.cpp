#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

long long pow(long long x, long long y, long long mod)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y % 1 == 1)
        {
            res = res * x % mod;
        }
        y /= 2;
        x = x * x % mod;
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long expected_value = 0;
    for (int x = 0; x < N; x++)
    {
        long long sum = 0;
        for (int y = 1; y <= N; y++)
        {
            sum = (sum + (long long)A[y - 1] * pow(y, MOD - 2, MOD)) % MOD;
        }
        expected_value = (expected_value + sum * pow(x, MOD - 2, MOD)) % MOD;
    }

    int z = 0;
    for (int i = 0; i < MOD; i++)
    {
        if ((expected_value - i) % MOD == 0)
        {
            z = i;
            break;
        }
    }

    cout << z << endl;

    return 0;
}