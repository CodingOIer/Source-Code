#include <cmath>
#include <cstdio>
const long long Mod = 998244353;
long long a, b;
long long answer;
long long solve(long long a, long long b)
{
    long long res = 0;
    for (long long i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            if (a / i != i)
            {
                res += 2;
            }
            else
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    scanf("%lld%lld", &a, &b);
    if (b % 2 == 1)
    {
        answer += ()
    }
    return 0;
}
/*
2 3
8
1 8
2 4

4 5
1 1024 5
2 512  5
4 256  5
8 128  5
16 64  5
32 32  5

2 5
32
1 32
2 16
4 8
*/