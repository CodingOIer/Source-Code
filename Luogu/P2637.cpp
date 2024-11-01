#include <algorithm>
#include <cstdio>
#include <functional>
constexpr int MaxN = 1e3 + 5;
int n, m;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + m, std::greater<>());
    int best = 0;
    int answer = 0;
    for (int i = 1; i <= std::min(n, m); i++)
    {
        if (p[i] * i >= answer)
        {
            answer = p[i] * i;
            best = p[i];
        }
    }
    printf("%d %d\n", best, answer);
    return 0;
}