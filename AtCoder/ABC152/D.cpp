#include <cmath>
#include <cstdio>
#include <map>
long long n;
long long answer;
std::map<long long, std::map<long long, long long>> map;
int get_number_len(long long x)
{
    int result;
    result = 0;
    for (; x != 0;)
    {
        result++;
        x /= 10;
    }
    return result;
}
int main()
{
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
    {
        map[i / (std::pow(10, get_number_len(i) - 1))][i % 10]++;
    }
    for (long long i = 1; i <= n; i++)
    {
        answer += map[i % 10][i / (std::pow(10, get_number_len(i) - 1))];
    }
    printf("%lld\n", answer);
    return 0;
}