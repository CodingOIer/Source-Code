#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    int l = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i]);
        l = std::max(l, int(strlen(s[i])));
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (s[j][i] != '\0')
            {
                printf("%c", s[j][i]);
            }
            else
            {
                int l = 0;
                for (int k = 1; k < j; k++)
                {
                    l = std::max(l, int(strlen(s[k])));
                }
                if (i < l)
                {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
    return 0;
}