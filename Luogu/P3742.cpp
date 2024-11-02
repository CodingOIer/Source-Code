#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
char t[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] < t[i])
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%s\n", t + 1);
    return 0;
}