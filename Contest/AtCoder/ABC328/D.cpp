#include <cstdio>
#include <cstring>
const int MaxN = 2e5 + 5;
int n;
char s[MaxN];
char k[MaxN];
void str_cpy(char *s, char *t)
{
    strcpy(k, t);
    strcpy(s, k);
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
        {
            str_cpy(s + i, s + i + 3);
            n -= 3;
            i = (i - 4 >= 0 ? i - 4 : 0);
        }
    }
    printf("%s\n", s + 1);
    return 0;
}