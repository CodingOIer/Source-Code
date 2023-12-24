#include <cstdio>
const int MaxN = 1e5 + 5;
int n;
int answer;
long long p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++)
    {
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] * p[i + 1] < 0)
        {
            answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}