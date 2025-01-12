#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, d;
int t[MaxN];
int l[MaxN];
int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &t[i], &l[i]);
    }
    for (int i = 1; i <= d; i++)
    {
        int answer = 0;
        for (int j = 1; j <= n; j++)
        {
            answer = std::max(answer, t[j] * (l[j] + i));
        }
        printf("%d\n", answer);
    }
    return 0;
}
