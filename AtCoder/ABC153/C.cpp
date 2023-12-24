#include <algorithm>
#include <cstdio>
const int MaxN = 2e5 + 5;
int n, k;
int p[MaxN];
long long answer;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n, [](int x, int y) { return x > y; });
    for (int i = k + 1; i <= n; i++)
    {
        answer += p[i];
    }
    printf("%lld\n", answer);
    return 0;
}