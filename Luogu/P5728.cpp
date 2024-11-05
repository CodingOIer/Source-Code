#include <cstdio>
#include <cstdlib>
constexpr int MaxN = 1e3 + 5;
int n;
int a[MaxN];
int b[MaxN];
int c[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (abs(a[i] - a[j]) <= 5 && abs(b[i] - b[j]) <= 5 && abs(c[i] - c[j]) <= 5 &&
                abs((a[i] + b[i] + c[i]) - (a[j] + b[j] + c[j])) <= 10)
            {
                answer++;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}