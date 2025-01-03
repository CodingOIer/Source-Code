#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n, k;
int p[MaxN];
long long prefix[MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        prefix[i] = prefix[i - 1] + p[i];
    }
    long long answer = 0;
    long long sum = 0;
    for (int i = k + 1; i <= n; i++)
    {
        sum += p[i] > 0 ? p[i] : 0;
    }
    answer = std::max(answer, sum + (prefix[k] > 0 ? prefix[k] : 0));
    for (int i = 1; i <= n - k; i++)
    {
        sum += p[i] > 0 ? p[i] : 0;
        sum -= p[i + k] > 0 ? p[i + k] : 0;
        answer = std::max(answer, sum + (prefix[i + k] - prefix[i] > 0 ? prefix[i + k] - prefix[i] : 0));
    }
    printf("%lld\n", answer);
    return 0;
}
