#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, k;
int p[MaxN];
std::vector<int> one;
std::vector<int> two;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        if (p[i] % 2 == 0)
        {
            two.push_back(p[i]);
        }
        else
        {
            one.push_back(p[i]);
        }
    }
    std::sort(one.begin(), one.end(), std::greater<>());
    std::sort(two.begin(), two.end(), std::greater<>());
    long long answer = 0;
    if (int(one.size()) >= k)
    {
        long long temp = 0;
        for (int i = 0; i < k; i++)
        {
            temp += one[i];
        }
        answer = std::max(answer, temp);
    }
    if (int(two.size()) >= k)
    {
        long long temp = 0;
        for (int i = 0; i < k; i++)
        {
            temp += two[i];
        }
        answer = std::max(answer, temp);
    }
    printf("%lld\n", answer);
    return 0;
}
