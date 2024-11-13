#include <bitset>
#include <cstdio>
#include <map>
constexpr int MaxN = 5e4 + 5;
constexpr int MaxM = 1e6 + 5;
int n;
int p[MaxN][7];
std::map<int, std::bitset<MaxN>> map;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            scanf("%d", &p[i][j]);
            map[p[i][j]][i] = true;
        }
    }
    std::bitset<MaxN> result;
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        result.reset();
        for (int j = 1; j <= 5; j++)
        {
            result |= map[p[i][j]];
        }
        answer += n - result.count();
    }
    printf("%lld\n", answer / 2);
    return 0;
}