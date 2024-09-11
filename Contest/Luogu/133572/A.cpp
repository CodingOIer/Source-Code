#include <cstdio>
#include <cstring>
const int MaxN = 1e5 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        if (strcmp(s, "AC") != 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}