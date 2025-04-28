#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
int answer;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i += 2)
    {
        answer += p[i];
    }
    printf("%d\n", answer);
    return 0;
}