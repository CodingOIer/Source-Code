#include <cstdio>
#include <map>
constexpr int MaxN = 2e5 + 5;
int n, c;
int p[MaxN];
std::map<int, int> map;
int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        map[p[i]]++;
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        map[p[i]]--;
        answer += map[p[i] - c];
        map[p[i]]++;
    }
    printf("%lld\n", answer);
    return 0;
}