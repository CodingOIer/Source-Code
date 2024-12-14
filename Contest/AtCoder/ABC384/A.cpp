#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
char d1, d2;
char s[MaxN];
int main()
{
    scanf("%d", &n);
    scanf(" %c", &d1);
    scanf(" %c", &d2);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != d1)
        {
            s[i] = d2;
        }
    }
    printf("%s", s + 1);
    return 0;
}
