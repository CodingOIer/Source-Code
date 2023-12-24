#include <cstdio>
const int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n - 2; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}