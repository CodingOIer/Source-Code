#include <cmath>
#include <cstdio>
#include <vector>
constexpr int MaxM = 3e7 + 5;
long long n;
int lessPrime[MaxM];
bool vis[MaxM];
std::vector<long long> prime;
void init(long long limit)
{
    vis[1] = true;
    for (int i = 2; i <= limit; i++)
    {
        if (vis[i])
        {
            continue;
        }
        prime.push_back(i);
        for (int j = 2 * i; j <= limit; j += i)
        {
            vis[j] = true;
        }
    }
    for (int i = 1; i <= limit; i++)
    {
        lessPrime[i] = lessPrime[i - 1] + (vis[i] ? 0 : 1);
    }
}
int main()
{
    scanf("%lld", &n);
    init(sqrt(n) + 3);
    long long sk1 = 0;
    for (const auto &val : prime)
    {
        if (val * val * val * val * val * val * val * val <= n)
        {
            sk1++;
        }
        else
        {
            break;
        }
    }
    long long sk2 = 0;
    for (const auto &val : prime)
    {
        long long sk = val * val;
        if (n - sk <= 0)
        {
            break;
        }
        sk2 += lessPrime[int(sqrt((long long)(n / sk)))];
        if (val <= int(sqrt((long long)(n / sk))))
        {
            sk2--;
        }
    }
    printf("%lld\n", sk1 + sk2 / 2);
    return 0;
}
