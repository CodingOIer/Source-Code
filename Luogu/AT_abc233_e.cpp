#include <cstdio>
#include <cstring>
constexpr int MaxN = 5e5 + 5;
int n;
int p[MaxN];
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += s[i] & 15;
    }
    for (int i = 1; i <= n; i++)
    {
        p[i] += sum;
        sum -= s[n - i + 1] & 15;
        p[i + 1] += p[i] / 10;
        p[i] %= 10;
    }
    for (int i = p[n + 2] != 0 ? n + 2 : p[n + 1] != 0 ? n + 1 : n; i >= 1; i--)
    {
        printf("%d", p[i]);
    }
    printf("\n");
    return 0;
}